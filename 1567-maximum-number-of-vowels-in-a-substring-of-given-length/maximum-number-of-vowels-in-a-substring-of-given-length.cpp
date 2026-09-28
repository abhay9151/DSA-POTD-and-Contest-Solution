class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<char> ans{'a', 'e', 'i', 'o', 'u'};
        int i = 0;
        int j = i + k;
        int len = 0;
        int max_len = 0;
        for (int x = i; x < j; x++) {
            if (find(ans.begin(), ans.end(), s[x]) != ans.end()) {
                len++;
            }
        }
        max_len = max(max_len, len);
        while (j < n) {
            if (find(ans.begin(), ans.end(), s[i]) != ans.end()) {
                len--;
            }
            if (find(ans.begin(), ans.end(), s[j]) != ans.end()) {
                len++;
            }
            max_len = max(max_len, len);
            i++;
            j++;
        }
        return max_len;
    }
};