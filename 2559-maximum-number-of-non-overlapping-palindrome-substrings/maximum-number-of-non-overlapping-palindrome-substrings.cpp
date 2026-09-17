class Solution {
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
        return true;
    }
    int solve(int index,string &s,int k,int n,vector<int>&dp){
        if(index>=n)return 0;
        if(dp[index]!=-1)return dp[index];
        int not_take=solve(index+1,s,k,n,dp);
        int take=0;
        for(int j=index+k-1;j<n;j++){
            if(ispalindrome(s,index,j)){
                take=1+solve(j+1,s,k,n,dp);
                break;
            }
        }
        return dp[index]=max(take,not_take);
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,k,n,dp);
    }
};