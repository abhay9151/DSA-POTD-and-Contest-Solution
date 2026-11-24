class Solution {
public:
    int maxLength(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    for(int i = 0; i < n; i++) {
    long long g = 0;
    long long l=1;
    long long p = 1;
    for(int j = i; j < n; j++) {
        g = gcd(g, nums[j]);
        l = lcm(l, nums[j]);
        if(p <= LLONG_MAX / nums[j]) {
            p *= nums[j];
        } else {
            break;
        }
        if(p==g * l) {
            ans = max(ans, j - i + 1);
        }
    }
}   
    return ans;

    }
};