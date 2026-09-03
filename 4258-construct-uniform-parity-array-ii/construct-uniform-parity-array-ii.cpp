class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int minv=*min_element(nums1.begin(),nums1.end());
        int x=minv%2;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==x)continue;
            if(nums1[i]>minv && ((nums1[i]-minv)%2==x))continue;
            return false;
        }
        return true;
    }
};