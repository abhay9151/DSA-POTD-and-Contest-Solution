class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ans = 0, n = s.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            for (int j = i+k-1;j<n;j++) {
                int cnt = count(s.begin() + i, s.begin() + j + 1, '1');
                    if (cnt == k) {
                    if (ans) {
                        if(j - i + 1 < res.size()) res = s.substr(i, j - i + 1);
                        else if(j - i + 1 == res.size()) res = min(res, s.substr(i, j - i + 1));
                    }
                    else {
                        res = s.substr(i, j - i + 1);
                        ans = 1;
                    }
                }
            }
        }
        return res;
    }
};