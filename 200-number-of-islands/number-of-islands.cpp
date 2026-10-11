class Solution {
    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<int>>&vis){
        int row=grid.size();
        int col=grid[0].size();
        if(r<0 ||c<0 || r>=row ||c>=col)return;
        if(vis[r][c] || grid[r][c]=='0')return ;
        vis[r][c]=1;
        dfs(grid,r+1,c,vis);
        dfs(grid,r-1,c,vis);
        dfs(grid,r,c+1,vis);
        dfs(grid,r,c-1,vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return count;
    }
};