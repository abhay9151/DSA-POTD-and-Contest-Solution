class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if(s == t) return 0;
        if(s.size() == 2) return -1;

        vector<int> fq(26, 0);
        for(auto& x : s) fq[x-'a']++;
        char mn = t[0], mx = t[n-1];

        if(s[0] == mn || s.back() == mx) return 1;
        if(s[0] == mx && s.back() == mn && fq[mx-'a'] == 1 && fq[mn-'a'] == 1) return 3;

        return 2;
    }
};