class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int res = -1, n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i] != i) res &= a[i];
        }
        return max(res, 0);
    }
};