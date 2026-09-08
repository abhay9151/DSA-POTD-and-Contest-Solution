class Solution {
public:
    const int M = 1e9 + 7;
    int dp[2001];
    vector<int> prev;
    // prev[n] = last position where this character was seen
    int solve(int n) {
        if(n == 0)return 1;   // empty subsequence
        if(dp[n] != -1)return dp[n];
        // take current + don't take current
        long long total = 2LL * solve(n - 1);
        // If current character appeared before,
        // duplicate subsequences are created
        if(prev[n] != 0) {
            total -= solve(prev[n] - 1);
        }
        total = (total % M + M) % M;
        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();
         memset(dp, -1, sizeof(dp));
        prev.assign(n + 1, 0);
        vector<int> lastSeen(26, 0);
        // Find previous occurrence of every character
        for(int i = 1; i <= n; i++) {
        int idx = s[i - 1] - 'a';
        prev[i] = lastSeen[idx];
        lastSeen[idx] = i;
        }
        // solve(n) includes empty subsequence
        // so subtract 1
        return (solve(n) - 1 + M) % M;
    }
};