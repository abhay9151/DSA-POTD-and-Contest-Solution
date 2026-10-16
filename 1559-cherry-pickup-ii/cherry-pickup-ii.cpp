class Solution {
    int n;
    int m;
    int solve(vector<vector<int>>& grid,int row,int col1,int col2,vector<vector<vector<int>>>&dp){
        if(row>=n)return 0;
        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
        int cherry=grid[row][col1];
        if(col1!=col2){
            cherry+=grid[row][col2];
        }
        int ans=-1e8;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int new_row=row+1;
                int new_col1=col1+i;
                int new_col2=col2+j;
                if (new_col1 >= 0 && new_col1< m && new_col2>=0 && new_col2<m) {
                    ans = max(ans, solve(grid, new_row, new_col1, new_col2,dp));
            }
        }
    }
        return dp[row][col1][col2]=cherry +ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};