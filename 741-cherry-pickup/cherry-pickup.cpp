class Solution {
    int n;
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2,vector<vector<vector<int>>>& dp) {
        int c2 = r1 + c1 - r2;
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n)return -1e8;
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)return -1e8;
        if(r1 == n-1 && c1 == n-1)return grid[r1][c1];
        if(dp[r1][c1][r2] != -1)return dp[r1][c1][r2];
        int cherry = grid[r1][c1];
        if(r1 != r2 || c1 != c2)cherry += grid[r2][c2];
        int a = solve(grid, r1+1, c1, r2, dp);
        int b = solve(grid, r1, c1+1, r2, dp);
        int c = solve(grid, r1+1, c1, r2+1, dp);
        int d = solve(grid, r1, c1+1, r2+1, dp);
        cherry += max(max(a,b), max(c,d));
        return dp[r1][c1][r2] = cherry;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(grid, 0, 0, 0, dp));
    }
};
