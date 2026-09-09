class Solution {
    int solve(vector<int>& satisfaction,int n,int index,int time,vector<vector<int>>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index][time]!=-1)return dp[index][time];
        int not_take=solve(satisfaction,n,index+1,time,dp);
        int take=satisfaction[index]*time+solve(satisfaction,n,index+1,time+1,dp);
        return dp[index][time]=max(take,not_take);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n =satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction,n,0,1,dp);
    }
};