class Solution {
public:
    int minChanges(string s) {
        char curr=s[0];
        int coscount=0;
        int minchange=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==curr){
                coscount++;
                continue;
            }
            if(coscount%2==0){
                coscount=1;
            }
            else{
                coscount=0;
                minchange++;
            }
            curr=s[i];
        }
        return minchange;
    }
};