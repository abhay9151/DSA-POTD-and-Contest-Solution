class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        double result = -1e9;
        int n = nums.size();
        int i = 0;
        int j = i + k;
        for (int x = i; x < j; x++) {
            ans += nums[x];
        }
        while (j <= n) {
            double average = ans / k;
            result = max(result, average);
            ans -= nums[i];
            i++;
            j++;
            if (j <= n) {
                ans += nums[j - 1];
            }
        }
        return result;
    }
};