class Solution {
    bool check(map<char,int>& need, map<char,int>& have){
       for(auto x : need){
        if(have[x.first] < x.second){
                return false;
            }

        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n=s.size();
        map<char,int>need;
        map<char,int>have;
        for(int i=0;i<t.size();i++){
            need[t[i]]++;
        }
        int len=INT_MAX;
        int low=0;
        int start=0;
        for(int high=0;high<n;high++){
            have[s[high]]++;
            while(check(need,have)){
                if(high-low+1<len){
                    len=high-low+1;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(len==INT_MAX){
            return "";
        }
        return s.substr(start,len);
    }
};