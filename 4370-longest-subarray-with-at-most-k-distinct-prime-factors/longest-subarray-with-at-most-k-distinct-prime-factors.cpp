class Solution {
public:
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }
         if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // Store prime factors of every number
        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            factors[i] = getPrimeFactors(nums[i]);
        }
        // Prime numbers are <= 100000
        vector<int> freq(100001, 0);
        int left = 0;
        int distinct = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            // Add nums[right]
            for (int p : factors[right]) {
                if (freq[p] == 0) {
                    distinct++;
                }

                freq[p]++;
            }

            // Shrink window if more than k primes
            while (distinct > k) {

                for (int p : factors[left]) {
                    freq[p]--;

                    if (freq[p] == 0) {
                        distinct--;
                    }
                }

                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};