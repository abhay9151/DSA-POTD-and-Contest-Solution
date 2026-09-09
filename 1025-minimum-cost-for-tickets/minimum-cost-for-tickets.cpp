class Solution {
    int solve(vector<int>& days, vector<int>& costs,int index,int n,vector<int>&dp){
        // base case
        if(index>=n)return 0;
        if(dp[index]!=-1)return dp[index];
        //1 day;
        int c=costs[0]+solve(days,costs,index+1,n,dp);
        int i;
        //7 days 
        for(i=index;i<n &&days[i]<days[index]+7;i++);
            int a=costs[1]+solve(days,costs,i,n,dp);
        //30 days
        for(i=index;i<n &&days[i]<days[index]+30;i++);
        int b=costs[2]+solve(days,costs,i,n,dp);
        
        return dp[index]=min(c,min(a,b));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,0,n,dp);
    }
};