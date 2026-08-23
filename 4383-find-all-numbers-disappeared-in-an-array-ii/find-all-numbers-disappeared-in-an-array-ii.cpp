class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
            vector<vector<int>>ans;
             unordered_set<int> st(nums.begin(), nums.end());
            vector<int>arr;
            for(int i=lower;i<=upper;i++){
                if(st.find(i) == st.end()) {
                arr.push_back(i);
                }
            }
            if(arr.size() == 0)return ans;
            vector<int>temp;
            temp.push_back(arr[0]);
            for(int j=1;j<arr.size();j++){
                if(arr[j]==arr[j-1]+1){
                    temp.push_back(arr[j]);
                }
                else {
                ans.push_back({temp[0], temp.back()});

                temp.clear();
                temp.push_back(arr[j]);
            }
        }
            ans.push_back({temp[0], temp.back()});
            return ans;
    }
};