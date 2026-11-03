class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int a=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ans+=abs(a-nums[i]);
        }
        return ans;
    }
};