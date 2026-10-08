class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=s.size();
        int m=p.size();
        if(m>n){
            return ans;
        }
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<m;i++){
            mp1[p[i]]++;
        }

        for(int j=0;j<m;j++){
            mp2[s[j]]++;
        }
        if(mp1==mp2){
            ans.push_back(0);
        }

        int i=0;
        int j=m;
        while(j<n){
            mp2[s[j]]++;
            mp2[s[i]]--;
            if(mp2[s[i]]==0){
                mp2.erase(s[i]);
            }
            if(mp1==mp2){
                ans.push_back(i+1);
            }
            i++;
            j++;
        }
        return ans;
    }
};