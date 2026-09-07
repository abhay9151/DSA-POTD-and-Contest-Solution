class Solution {

    int solve(string &s, int i, vector<int> &dp) {

        if(i == 0)
            return 1;   // empty subsequence

        if(dp[i] != -1)
            return dp[i];

        // take + not_take
        long long ans = 2LL * solve(s, i - 1, dp);

        // find previous occurrence of s[i-1]
        int j = i - 2;

        while(j >= 0 && s[j] != s[i - 1])
            j--;

        // remove duplicate subsequences
        if(j >= 0) {
            ans -= solve(s, j, dp);
        }

        ans = (ans + 1000000007) % 1000000007;

        return dp[i] = ans;
    }

public:

    int distinctSubseqII(string s) {

        int n = s.size();

        vector<int> dp(n + 1, -1);

        // remove empty subsequence
        return (solve(s, n, dp) - 1 + 1000000007) % 1000000007;
    }
};