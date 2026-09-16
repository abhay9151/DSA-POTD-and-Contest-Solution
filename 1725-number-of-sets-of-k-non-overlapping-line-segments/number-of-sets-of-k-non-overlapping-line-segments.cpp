class Solution {
    long long M= 1000000007;
    // int solve(int n,int start,int k,vector<vector<int>>&dp){
    //     if(k==0)return 1;
    //     if(start>=n-1){
    //         return 0;
    //     }
    //     if(dp[start][k]!=-1)return dp[start][k];
    //     long long not_take=solve(n,start+1,k,dp);
        //long long take=0;
    //     for(int i=start+1;i<n;i++){
    //         take+=solve(n,i,k-1,dp);
    //         take%=MOD;
    //     }
    //     return dp[start][k]=take;
    // }
public:
    int numberOfSets(int n, int K) {
    vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));
         //agar k==0 return karna he 1 par i<n bhi hona chaiye hamesha
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        for(int k =1;k<=K; k++) {
        vector<int> prevRowSum(n + 1, 0);
            for(int x = n-1;x>= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }
            for(int i = n-2;i>=0; i--) {
                int take =prevRowSum[i + 1];
                int skip = dp[k][i + 1];
                dp[k][i] = (take + skip) % M;
            }
        }return dp[K][0];
    }
};