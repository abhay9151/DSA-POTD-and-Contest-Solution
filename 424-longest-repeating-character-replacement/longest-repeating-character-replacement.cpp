class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        map<char,int>mp;
        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;

        while(j<n){
            mp[s[j]]++;

            maxi=max(maxi,mp[s[j]]);

            while((j-i+1)-maxi>k){
                mp[s[i]]--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};