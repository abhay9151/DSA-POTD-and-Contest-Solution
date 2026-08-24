class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
    int n=stones.size();
    int sum=0;
    for(int i: stones)sum+=i;
    int ans=sum;
    sum-=stones[n-1];
    for(int i=n-2;i>0;i--){
       ans=max(ans,sum-ans);
       sum-=stones[i];
    } 
    return ans;
    }
};