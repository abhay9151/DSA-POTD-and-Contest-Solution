class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+4, INT_MAX);
        dp[n+1] = 0;
        dp[n+2] = 0;
        dp[n+3] = 0;
        for(int index=n; index>=1; index--) {
            int a = costs[index-1] + 1 + dp[index+1];
            int b = INT_MAX, c = INT_MAX;
            if(index+1 <= n) {
                b = costs[index] + 4 + dp[index+2];
            }
            if(index+2 <= n) {
                c = costs[index+1] + 9 + dp[index+3];
            }
            dp[index] = min({a,b,c});
        }
        return dp[1]; 
    }
};


// class Solution {
//     int solve(int index, int n, vector<int>& costs,vector<int>&dp) {
//         if(index > n) return 0;
//         if(dp[index] != -1) return dp[index];
//         int a = INT_MAX, b = INT_MAX, c = INT_MAX;
//         a = costs[index-1] +1+ solve(index+1,n,costs,dp);
//         if(index+1 <= n) {
//             b = costs[index]+4 + solve(index+2,n,costs,dp);
//         }
//         if(index+2 <= n) {
//             c = costs[index+1]+9+solve(index+3,n,costs,dp);
//         }
//         return dp[index]=min({a,b,c});
//     }

// public:
//     int climbStairs(int n, vector<int>& costs) {
//         vector<int>dp(n+1,-1);
//         return solve(1,n,costs,dp);
//     }
// };