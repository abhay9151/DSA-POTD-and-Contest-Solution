class Solution {
    void solve(int index, string &digits, vector<string> &mp,string &temp, vector<string> &ans) {
        // Base case
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[index] - '2'];
        for(char ch : letters) {
            temp.push_back(ch);
            solve(index + 1, digits, mp, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mp = { "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans;
        string temp;
        solve(0, digits, mp, temp, ans);
        return ans;
    }
};