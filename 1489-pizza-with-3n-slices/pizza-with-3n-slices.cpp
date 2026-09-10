// this question is basically like house robber question
class Solution {
        int solve(int index,vector<int>&temp,vector<vector<int>>&dp,int k){
            if(k==0)return 0;
            if(index<0) return INT_MIN;
            if(dp[index][k]!=-1) return dp[index][k];
            int pick=temp[index]+solve(index-2,temp,dp,k-1);
            int notpick=solve(index-1,temp,dp,k);
            return dp[index][k]=max(pick,notpick);
        }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k=n/3;
        if(n == 1) return slices[0];
        vector<int> temp1(slices.begin(),slices.end() - 1); //First house ko consider karo
        vector<int> temp2(slices.begin() + 1,slices.end()); //First house ko consider karo
        vector<vector<int>>dp1(temp1.size(),vector<int>(k+1,-1));
        vector<vector<int>>dp2(temp2.size(),vector<int>(k+1,-1));
        //Dono cases mein se jo zyada paisa deta hai, wahi answer hoga:
        int ans1 = solve(temp1.size() - 1, temp1, dp1,k);
        int ans2 = solve(temp2.size() - 1, temp2, dp2,k);
        return max(ans1, ans2);
    }
};