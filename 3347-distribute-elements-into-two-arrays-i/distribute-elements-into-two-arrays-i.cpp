class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>s;
        s.push_back(nums[0]);
        vector<int>q;
        q.push_back(nums[1]);
        
        
        for(int i=2;i<nums.size();i++){
            if(s.back()>q.back()){
                s.push_back(nums[i]);
            }
            else{
                q.push_back(nums[i]);
            }
        }
        s.insert(s.end(), q.begin(), q.end());  
        return s;

    }
};