class Solution {
public:
    vector<int> pt;

    int find(int x){
        if(x == pt[x]) return x;
        return pt[x] = find(pt[x]);
    }
    
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 1) return arr;

        pt.assign(n, 0);
        vector<int> temp = arr;
        for(int i = 0; i < n; i++) pt[i] = i;

        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] <= k){
                int u = find(i), v = find(i-1);
                pt[u] = v;
            }
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = pt[i];
        }

        unordered_map<int, vector<int>> mp1;
        for(int i = n - 1; i >= 0; i--) mp1[mp[arr[i]]].push_back(arr[i]);

        for(int i = 0; i < n; i++){
            int currPt = mp[temp[i]];
            arr[i] = mp1[currPt].back();
            mp1[currPt].pop_back();
        }

        return arr;
    }
};