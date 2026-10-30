class Solution {
    unordered_set<string>st;
    int n;
    bool solve(string &s,unordered_set<string>&st,int index,vector<int>&dp){
        if(index==n)return true;
        if(dp[index]!=-1)return dp[index];
        for(int i=index;i<n;i++){
            string temp=s.substr(index,i-index+1);
            // recursion baar baar call karte rahenge ham.
            if(st.count(temp) && solve(s,st,i+1,dp)){
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        vector<int>dp(n,-1);
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return solve(s,st,0,dp);
    }
};