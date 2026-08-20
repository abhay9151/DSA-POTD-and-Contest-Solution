// Minimum insertions = n - Longest Palindromic Subsequence (LPS)
class Solution {
public:
    int solve(string &s,string &revs,int i,int j,vector<vector<int>>&dp){
        if(i==s.length()){
            return 0;
        }
        if(j==revs.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==revs[j]){
            ans=1+solve(s,revs,i+1,j+1,dp);
        }
        else{
            ans=max(solve(s,revs,i+1,j,dp),solve(s,revs,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        int n=s.size();
        string revs = s;
        reverse(revs.begin(),revs.end());
        vector<vector<int>>dp(s.length(),vector<int>(revs.length(),-1));
        return n-solve(s,revs,0,0,dp);
    }
};