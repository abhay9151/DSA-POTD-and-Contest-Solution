class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low < high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            int parts = 1; 
            for(int i = 0; i < n; i++) {
                if(sum + nums[i] > mid) {
                    parts++;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
            if(parts > k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};