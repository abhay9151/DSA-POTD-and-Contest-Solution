class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp1;
            unordered_map<int,int>mp2;
            int a=0;
            int v=0;
            for(int j=i;j<n;j++){
                int val=nums[j];
                if(mp1[val]==0){
                    a++;
                    mp2[val]=a;
                }
                mp1[val]++;
                if(mp1[val]==mp2[val]){
                    v++;
                }
                else if(mp1[val]==mp2[val]+1){
                    v--;
                }
                if(v==a){
                    ans++;
                }
            }
        }
        return ans;
    }
};