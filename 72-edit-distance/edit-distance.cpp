class Solution {
    int solve(int i,int j,string word1,string word2, vector<vector<int>>&dp){
        if(i==0)return j;
        if(j==0) return i;
        if(word1[i-1]==word2[j-1]){
            return solve(i-1,j-1,word1,word2,dp);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        else{
            int insert=solve(i,j-1,word1,word2,dp);
            int delete1=solve(i-1,j,word1,word2,dp);
            int update=solve(i-1,j-1,word1,word2,dp);
            return dp[i][j]=1+min({insert,update,delete1});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,word1,word2,dp);
    }
};