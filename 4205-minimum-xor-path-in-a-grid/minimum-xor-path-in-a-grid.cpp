class Solution {
public:
	int n, m;
	vector<vector<vector<int>>> dp;

	int solve(int i, int j, int k, vector<vector<int>>& a) {
		if (i >= n || j >= m) return INT_MAX;

		k ^= a[i][j];

		if (i == n - 1 && j == m - 1)
			return k;

		if (dp[i][j][k] != -1) return dp[i][j][k];

		return dp[i][j][k] = min(solve(i + 1, j, k, a), solve(i, j + 1, k, a));
	}

	int minCost(vector<vector<int>>& a) {
		n = a.size(), m = a[0].size();
		dp.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));
		return solve(0, 0, 0, a);
	}
};