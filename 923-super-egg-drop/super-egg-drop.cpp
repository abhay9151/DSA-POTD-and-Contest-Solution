class Solution {
    int solve(int k, int n, vector<vector<int>>& dp) {
        if(n == 1) return 1;
        if(n == 0) return 0;
        if(k == 1) return n;
        if(dp[k][n] != -1)return dp[k][n];
        int maxi = INT_MAX;
        int low = 1;
        int high = n;
        while(low <= high) {
            int i = low + (high - low) / 2;
            int broked = solve(k - 1, i - 1, dp);
            int not_broken = solve(k, n - i, dp);
            int worstcase = 1 + max(broked, not_broken);
            maxi = min(maxi, worstcase);    
            if(broked < not_broken) {
                low = i + 1;
            }
            else {
                high = i - 1;
            }
        }
        return dp[k][n] = maxi;
    }

public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};