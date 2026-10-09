class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), ans = 0;
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ')') stk.push(i);
            else{
                if(stk.empty()){
                    ans += 2;
                    continue;
                }
                int x = stk.top(); stk.pop();
                if(!stk.empty() && stk.top() == x + 1) stk.pop();
                else ans++;
            }
        }

        while(!stk.empty()){
            int x = stk.top(); stk.pop();
            if(!stk.empty() && stk.top() == x + 1) stk.pop();
            else ans++;
            ans++;
        }

        return ans;
    }
};