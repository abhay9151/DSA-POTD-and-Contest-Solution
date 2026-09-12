class Solution {
    int k;
    long long solve(int n,int target,int k,vector<vector<int>>&dp){
        if(target<0)return 0;
        if(n==0){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[n][target]!=-1)return dp[n][target];
        long long take=0;
        for(int i=1;i<=k;i++){
            take+=(solve(n-1,target-i,k,dp));
            take %= 1000000007;
        }
        return dp[n][target]=take;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,target,k,dp);
    }
};