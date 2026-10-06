class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int count = 0;// open brackets
        int count1 = 0;// extra closing brackets

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                count++;
            }
            else{
                if(count > 0){
                    count--;
                }
                else{
                    count1++;
                }
            }
        }
        return count + count1;
    }
};
