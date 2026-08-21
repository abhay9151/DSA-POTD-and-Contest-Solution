class Solution {
    vector<vector<int>> temp;
    void solve(vector<int>& nums, int index, int n) {
        if(index == n) {
            temp.push_back(nums);
            return;
        }
        for(int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            solve(nums, index + 1, n);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(nums, 0, n);
        return temp;
    }
};