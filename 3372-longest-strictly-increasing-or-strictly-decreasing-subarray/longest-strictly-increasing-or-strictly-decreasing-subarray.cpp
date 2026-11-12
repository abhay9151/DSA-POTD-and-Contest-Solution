class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int c1 = 1, c2 = 1, n = a.size(), ans = 1;

        for(int i = 1; i < n; i++){
            if(a[i] > a[i-1]) c1++;
            else c1 = 1;
            if(a[i] < a[i-1]) c2++;
            else c2 = 1;

            ans = max(ans, max(c1, c2));
        }

        return ans;
    }
};