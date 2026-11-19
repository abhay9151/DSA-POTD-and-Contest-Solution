class Solution {
public:
    int minimizeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        return min(a[n-2] - a[1], min(a[n-3] - a[0], a[n-1] - a[2]));
    }
};