class Solution {
   vector<string>result;
    unordered_set<string>st;
    int n;
public:
    void solve(int i,string &s,string &ans){
        if(i>=n){
            result.push_back(ans);
            return;
        }
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(st.count(temp)){
                string a=ans;
                if(!ans.empty())ans+=" ";
                ans+=temp;
                solve(j+1,s,ans);
                ans=a;
             }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        string ans="";
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        solve(0,s,ans);
        return result; 
    }
};