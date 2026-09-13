class Solution {
    int solve(vector<int>&nums,int n,int prev,int d,vector<vector<int>>&dp){
        if(dp[prev][d+500]!=-1)return dp[prev][d+500];
        int take=0;
       for(int curr=prev+1;curr<n;curr++){
        if(nums[curr]-nums[prev]==d){
            //ifference same rakhte huye age kitne element le sakte ho recursion se nikalo
            take=max(take,1+solve(nums,n,curr,d,dp));
        }
    }
    return dp[prev][d+500]=take;
}
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,-1));
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i];//nikale huye difference ke according age chalke kitne subsequences he unko recursion se nikalo.
                int length=2+solve(nums,n,j,d,dp);
                ans=max(ans,length);
            }
        }
        return ans;
    }
};

// Ye jo he 3D dp ka concept he jisse hum memory limit exceed araha he 
// class Solution {
//     int solve(vector<int>&nums,int n,int prev,int curr,int d,vector<vector<vector<int>>>&dp){
//         if(curr>=n)return 0;
//         if(dp[prev][curr][d+500]!=-1)return dp[prev][curr][d+500];
//         int take=0;
//         if(nums[curr]-nums[prev]==d){
//             take=1+solve(nums,n,curr,curr+1,d,dp);
//         }
//         int not_take=solve(nums,n,prev,curr+1,d,dp);
//         return  dp[prev][curr][d+500]=max(take,not_take);
//     }
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(1001,-1)));
//         int ans=2;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int d=nums[j]-nums[i];//nikale huye difference ke according age chalke kitne subsequences he unko recursion se nikalo.
//                 int length=2+solve(nums,n,j,j+1,d,dp);
//                 ans=max(ans,length);
//             }
//         }
//         return ans;
//     }
// };