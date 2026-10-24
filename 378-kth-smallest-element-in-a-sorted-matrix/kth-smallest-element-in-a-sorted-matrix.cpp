class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        pq.push({matrix[0][0],{0,0}});
        vis[0][0]=1;
        int row[]={0,1};
        int col[]={1,0};
        while(!pq.empty()){
            int value=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            k--;
            if(k==0){
                return value;
            }
            for(int i=0;i<2;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow<n && ncol<m && !vis[nrow][ncol]){
                    pq.push({matrix[nrow][ncol],{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return -1;
    }
};