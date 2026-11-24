class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            long long pro=1,g=0,l=1,maxLcm = 100000000000;;
            for(int j=i;j<n;j++){
                pro *=nums[j];
                if(pro > maxLcm) break;
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(pro== g*l) maxi=max(maxi,j-i+1);
            } 
        }
        return maxi;
    }
};