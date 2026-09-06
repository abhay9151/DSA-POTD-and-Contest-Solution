class Solution {
    // int solve(vector<int>&values,int i,int j,vector<vector<int>>&dp){
    //     if(i+1==j)return 0;
    //     int mini=INT_MAX;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     for(int k=i+1;k<j;k++){
    //         int cost=values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int mini=INT_MAX;
                for(int k=i+1;k<j;k++){
                int cost=values[i]*values[j]*values[k]+dp[i][k]+dp[k][j];
                mini=min(mini,cost);
                } 
                dp[i][j]=mini;
            }
        }
        // return solve(values,0,n-1,dp);
        return dp[0][n-1];
    }
};