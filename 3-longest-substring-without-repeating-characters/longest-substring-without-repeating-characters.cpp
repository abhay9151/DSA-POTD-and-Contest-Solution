class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)return 0;
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        int j=0;
        int i=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(mp[s[j]]>1){
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};