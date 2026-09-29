class Solution {
        int solve(string &s1,string &s2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i == n) {
            int sum = 0;
        for(int k = j; k < m; k++) {
                sum += s2[k];
            }
        return sum;
        }
        if(j == m) {
            int sum = 0;
            for(int k = i; k < n; k++) {
                sum +=s1[k];
            }
        return sum;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j]) {
            return solve(s1, s2, n, m, i + 1, j + 1,dp);
        }
        int a = s1[i] + solve(s1, s2, n, m, i + 1, j,dp);
        int b = s2[j] + solve(s1, s2, n, m, i, j + 1,dp);
        return dp[i][j]=min(a, b);
        }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s1,s2,n,m,0,0,dp);
    }
};