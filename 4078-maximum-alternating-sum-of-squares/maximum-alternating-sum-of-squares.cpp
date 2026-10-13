// firstly we will sort the array absolute sorting 
// because we have to return max sum then we will add last element and subtract from first thill mid .

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b) {
            return abs(a) < abs(b);
        });
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        long long pos = 0;
        int num = (n) / 2;
        while (i < num && j >= num) { 
            pos += 1LL * nums[j] * nums[j];
            pos -= 1LL * nums[i] * nums[i];
            i++;
            j--;
        }
        if (n % 2 != 0) {
            pos += 1LL*nums[num] * nums[num];
        }
        return pos;
    }
};
