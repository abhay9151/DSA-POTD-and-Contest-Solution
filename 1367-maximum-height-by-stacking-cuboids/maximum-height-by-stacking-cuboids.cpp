class Solution {
    bool check(vector<int>base,vector<int>newbox){
        if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int curr,int prev,vector<vector<int>>&a,int n,vector<vector<int>>&dp){
        if(curr>=n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int take=0;
        if(prev==-1 || check(a[prev],a[curr])){
            take=a[curr][2]+solve(curr+1,curr,a,n,dp);
        }
        int not_take=solve(curr+1,prev,a,n,dp);
        return dp[curr][prev+1]=max(take,not_take);

    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(cuboids.rbegin(),cuboids.rend());
        return solve(0,-1,cuboids,n,dp);
    }
};