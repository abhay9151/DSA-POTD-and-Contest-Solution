
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                int ans=mp.size();
                count+=ans*ans;
            }
        }
        return count;
    }
};
