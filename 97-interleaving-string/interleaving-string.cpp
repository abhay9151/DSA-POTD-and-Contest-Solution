class Solution {
    bool solve(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size())return true;
        
        if(i+j>=s3.size()){
            return dp[i][j]=false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool result=false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            result=solve(s1,s2,s3,i+1,j,dp);
        }
        if(result==true)return dp[i][j]=result;
        if(j<s2.size() &&s2[j]==s3[i+j]){
            result=solve(s1,s2,s3,i,j+1,dp);
        }
        return dp[i][j]=result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size())return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};