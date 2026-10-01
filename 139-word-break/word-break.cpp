class Solution {
    int n;
    bool solve(string &s,int index,vector<string>& wordDict,vector<int>&dp){
        if(index==n)return true;
        if(dp[index]!=-1)return dp[index];
        for(int i=1;index+i<=n;i++){
            string temp=s.substr(index,i);
            if(find(wordDict.begin(), wordDict.end(),temp)!=wordDict.end() && solve(s,index+i,wordDict,dp)){
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(s,0,wordDict,dp);
    }
};