class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!open.empty()){// agar open bracket ajata he to pop
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return 0;
                }
            }
        }
        // matching remaining '(' with '*'
        while (!open.empty()) {
            if (star.empty()) return false;
            if (star.top() < open.top()) return false;
            //Agar '*' '(' se pehle aaya hai to wo closing bracket nahi ban sakta. To basically hamane bas index compare karliye.
            star.pop();
            open.pop();
        }
        return true;
        }
};