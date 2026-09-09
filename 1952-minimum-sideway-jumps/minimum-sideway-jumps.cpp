class Solution {
    int solve(int n,vector<int>& obstacles,int currlane,int pos,vector<vector<int>>&dp){
        if(pos>=n)return 0;
        // agr samne wali lane me age koi bhi obstacles nhi he to seedha chale jana he.
        if(dp[currlane][pos]!=-1)return dp[currlane][pos];
        if(obstacles[pos+1]!=currlane){
            return dp[currlane][pos]=solve(n,obstacles,currlane,pos+1,dp);
        }
        // manlo agar age obstacles he to apni hi lane me nhi kudega aor jislane me kude ga uslane me obstacles nhi hone chaiye.
        int jump=INT_MAX;
        for(int k=1;k<=3;k++){
            if(currlane!=k && obstacles[pos]!=k){
                jump=min(jump,1+solve(n,obstacles,k,pos,dp));
            }
        }
        return dp[currlane][pos]=jump;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()-1;
        vector<vector<int>>dp(4,vector<int>(n+1,-1));
        return solve(n,obstacles,2,0,dp);
    }
};