class Solution {
    double solve(int a,int b,vector<vector<double>>&dp){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0)return 1.0;
        if(b<=0) return 0.0;
        if(dp[a][b]!=-1)return dp[a][b];
        double ans=0.0;
        ans+=solve(a-4,b,dp);
        ans+=solve(a-3,b-1,dp);
        ans+=solve(a-2,b-2,dp);
        ans+=solve(a-1,b-3,dp);
        return dp[a][b]=ans/4.0;

    }
public:
    double soupServings(int n) {
        if(n>=4800) return 1.0;
        n=(n+24)/25;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};