class Solution {
    int solve(vector<int>&stones,int k,int index,vector<vector<int>>&dp){
        if(index==stones.size()-1){
            return true;
        }
        if(dp[k][index]!=-1)return dp[k][index];
        for(int jump=k-1;jump<=k+1;jump++){
            if(jump<=0)continue;
            int next=stones[index]+jump;
            for(int i=index+1;i<stones.size();i++){
                //The frog Successfully reached stone i.Now continue solving the problem from this new stones with jump as jumpsize
                if(stones[i]==next){
                    if(solve(stones,jump,i,dp)){
                        return dp[k][index]=1;// return true->from this stone the frog eventually reached the final stone.
                    }
                    else{
                        break;// I found the required next stone ,stop searching for the particular jump.
                    }
                }
            }
        }
        return dp[k][index]=0;

    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1] != 1)return false;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(stones,1,1,dp);
    }
};