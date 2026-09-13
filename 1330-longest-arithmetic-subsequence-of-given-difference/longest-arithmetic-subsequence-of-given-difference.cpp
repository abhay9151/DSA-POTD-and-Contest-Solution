class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int>dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-d;
            int tempans=0;
            if(dp.count(temp)){
                // agar temp jo he dp me exits karta he to 1 plus 
                tempans=dp[temp];
            }
            dp[arr[i]]=1+tempans;
            ans=max(ans,dp[arr[i]]);
      }
      return ans;
    }
};


// class Solution {
//     // int solve(vector<int>&arr,int n,int d,int prev,vector<int>&dp){
//     //     if(prev>=n)return 0;
//     //     if(dp[prev]!=-1)return dp[prev];
//     //     int take=0;
//     //     for(int curr=prev+1;curr<n;curr++){
//     //         if(arr[curr]-arr[prev]==d){
//     //             int len=1+solve(arr,n,d,curr,dp);
//     //             take=max(take,len);
//     //         }
//     //     }
//     //     return dp[prev]=take;
//     // }
    
// //.   This is the tle appproach. 
// public:
//     int longestSubsequence(vector<int>& arr, int d) {
//         int n=arr.size();
//         vector<int>dp(n,1);
//         int ans=1;
//         // for(int i=0;i<n;i++){
//         //     int length=1+ solve(arr,n,d,i,dp);
//         //     ans=max(ans,length);
//         // }
//         for(int prev=n-1;prev>=0;prev--){
//             for(int curr=prev+1;curr<n;curr++){
//             if(arr[curr]-arr[prev]==d){
//                 int len=1+dp[curr];
//                 dp[prev]=max(dp[prev],len);
//             }
//         }
//          ans = max(ans, dp[prev]);
//         }
//         return ans;
//     }
// };