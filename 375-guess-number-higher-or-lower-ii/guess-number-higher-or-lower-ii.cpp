class Solution {
        int solve(int start,int end,vector<vector<int>>&dp){
            if(start>=end)return 0;
            int mini=INT_MAX;
            if(dp[start][end]!=-1)return dp[start][end];
            for(int i=start;i<=end;i++){
            int left=solve(start,i-1,dp);
            int right=solve(i+1,end,dp);
            int ans=i+max(left,right);
            mini=min(mini,ans);
            }
            return dp[start][end]=mini;
        }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,dp);
    }
};