class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi_index = -1;
        int mini_index = -1;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                maxi_index = i;
            }

            if (nums[i] == mini) {
                mini_index = i;
            }
        }
        int a = max(maxi_index, mini_index) + 1;
        int b = n - min(maxi_index, mini_index);
        int c = min(maxi_index, mini_index) + 1+n-max(maxi_index,mini_index);
        return min({a, b, c});
    }
};