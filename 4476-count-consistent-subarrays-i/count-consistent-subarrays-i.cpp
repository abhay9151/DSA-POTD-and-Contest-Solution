class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int ele = nums[i];
            for (int j = i; j < n; j++) {
                ele = ele&nums[j];
                if (mini > nums[j]) {
                    mini = nums[j];
                }

                if (ele == mini) {
                    count++;
                }
            }
        }
        return count;
    }
};