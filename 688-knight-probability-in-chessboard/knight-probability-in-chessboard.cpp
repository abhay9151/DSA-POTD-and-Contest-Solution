class Solution {
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    double solve(int n, int k, int row, int column, vector<vector<vector<double>>>&dp) {
        if(row < 0 || row >= n|| column<0||column>=n)return 0.0;
        if(k == 0)return 1.0;
        if(dp[k][row][column]!=-1.0)return dp[k][row][column];
        double ans = 0;
        for(int i = 0; i < 8; i++) {
            ans += solve(n, k - 1,row + dx[i],column + dy[i],dp);
        }
        return dp[k][row][column]=ans/8.0;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return solve(n, k, row, column,dp);
    }
};