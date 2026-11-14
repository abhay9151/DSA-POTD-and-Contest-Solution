class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int ans = INT_MAX, n = a.size(), sum;

        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += a[j];
                if(j - i + 1 > r) break;
                if(j - i + 1 >= l && sum > 0) ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};