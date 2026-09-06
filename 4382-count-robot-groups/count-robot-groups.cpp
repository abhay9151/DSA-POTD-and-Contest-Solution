class Solution {
public:
    int countGroups(vector<int>& p, vector<int>& s, int d) {
        int ans = 0, n = p.size(), r = n - 1;
        long long curr = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if(s[i] <= curr && p[i+1] - p[i] > d){
                ans++;
                curr = s[i];
            }
        }
        ans++;
        return ans;
    }
};