class Solution {
public:
    int n;

    long long solve(int i, int x, int mult, int k,
                    vector<vector<long long>>& dp, vector<int>& a) {
        if (i == n)
            return 0;

        if (dp[i][mult + 1] != -1)
            return dp[i][mult + 1];

        long long ans = 0;

        if (mult == -1) {
            if (a[i] == x)
                ans++;

            ans += solve(i + 1, x, -1, k, dp, a);
            ans += solve(i + 1, x, a[i], k, dp, a);
        } else {
            int temp = (mult * a[i]) % k;

            if (temp == x)
                ans++;

            ans += solve(i + 1, x, temp, k, dp, a);
        }

        return dp[i][mult + 1] = ans;
    }

    vector<long long> resultArray(vector<int>& a, int k) {
        n = a.size();

        for (int& x : a)
            x %= k;

        vector<long long> res;

        for (int x = 0; x < k; x++) {
            vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));

            res.push_back(solve(0, x, -1, k, dp, a));
        }

        return res;
    }
};