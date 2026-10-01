class Solution {
    bool isConcatenated(string word,unordered_set<string>&st, unordered_map<string, int>&dp){
        int n=word.size();
      if(dp.find(word)!=dp.end())return dp[word];
        for(int i=0;i<n-1;i++){
            string prefix=word.substr(0,i+1);
            string suffix=word.substr(i+1);
            if(st.find(prefix)!=st.end() && isConcatenated(suffix,st,dp) ||st.find(prefix)!=st.end() && st.find(suffix)!=st.end()){
                return dp[word]=true;
            }
        }
        return dp[word]=false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st(words.begin(),words.end());
        vector<string>result;
        unordered_map<string, int>dp;
        for(int i=0;i<n;i++){
            string word=words[i];
            if(isConcatenated(word,st,dp)){
                result.push_back(word);
            }
        }
        return result;
    }
};