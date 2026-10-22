class Solution {
    bool cycle = false;
    void dfs(int node, vector<int>& vis, vector<int>& path,vector<vector<int>>& adj) {
        vis[node] = 1;
        path[node] = 1;
        for(int j = 0; j < adj[node].size(); j++) {
            int neigh = adj[node][j];
            if(path[neigh] == 1) {
                cycle = true;
                return;
            }
            if(vis[neigh] == 0) {
                dfs(neigh, vis, path, adj);
            }
            if(cycle) return;
        }

        path[node] = 0;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][0];
            int dist = prerequisites[i][1];

            adj[dist].push_back(src);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, path, adj);
            }

            if(cycle) return false;
        }

        return true;
    }
};