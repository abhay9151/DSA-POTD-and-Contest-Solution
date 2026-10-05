class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        vector<int>ans;
        int total=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ans.push_back(total);
                total=0;
            }
            else{//')'
                    if(s[i-1]=='('){
                        total=ans.back()+1;
                    }
                    else{
                        total=ans.back()+2*total;
                    }
            ans.pop_back();
            }
        }
        return total;
    }
};