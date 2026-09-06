class Solution {
    int solve(vector<int>&values,int i,int j,vector<vector<int>>&dp){
        if(i+1==j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i+1;k<j;k++){
            int cost=values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};