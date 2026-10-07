// Time Complexity is ->O(2^N *N)
// the constaints is very less and also isme either hame take karna padega yato remove karna padega aor sare valid possibilites nikalni padegi.
class Solution {
        set<string>result;
        void solve(string &s,int count ,int index,string &curr){
            if(count<0)return ;
            if(index==s.size()){
                if(count==0){
                    result.insert(curr);
                }
                return ;
            }
            // take the character 
            // string valid he ki nhi check karne ke liye yahhi sabse valid tarika he.
            if(s[index]=='('){
                curr+=s[index];
                solve(s,count+1,index+1,curr);
                curr.pop_back();
            }
            else if(s[index]==')'){
                curr+=s[index];
                solve(s,count-1,index+1,curr);
                curr.pop_back();
            }
            // ko beech me agya jaise 'a'.
            else{
                curr+=s[index];
                solve(s,count,index+1,curr);
                curr.pop_back();
            }
            // remove current character
            solve(s,count,index+1,curr);
        }
public:
    vector<string> removeInvalidParentheses(string s) {
        string curr="";
        int maxlen=INT_MIN;
        solve(s,0,0,curr);
        vector<string>ans(result.begin(),result.end());
        // jo answer me sabse madi length ki string hogi whi answer hoga.
        for(int i=0;i<ans.size();i++){
            int len=ans[i].length();
            maxlen=max(maxlen,len);
        }
        vector<string>a;
        for(int i=0;i<ans.size();i++){
            if(ans[i].length()==maxlen){
                a.push_back(ans[i]);
            }
        }
        return a;
    }
};