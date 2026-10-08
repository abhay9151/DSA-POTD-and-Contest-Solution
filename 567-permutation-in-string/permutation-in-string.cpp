class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(n>m){
            return false;
        }

        map<char,int>mps1;
        map<char,int>mps2;

        for(int i=0;i<n;i++){
            mps1[s1[i]]++;
            mps2[s2[i]]++;
        }

        if(mps1==mps2){
            return true;
        }
        int i=0;
        int j=n;
        while(j<m){
            mps2[s2[j]]++;
            mps2[s2[i]]--;
            if(mps2[s2[i]]==0){
                mps2.erase(s2[i]);
            }
            if(mps1==mps2){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
};