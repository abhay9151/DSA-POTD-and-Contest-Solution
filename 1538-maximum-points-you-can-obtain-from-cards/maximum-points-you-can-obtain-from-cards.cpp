class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int mini=INT_MAX;
        int n=cardPoints.size();
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
        }
        if(k == n) return sum;
        int i=0;
        int j=0;
        int sumi=0;
        while(j<n){
            sumi+=cardPoints[j];
            if(j-i+1<n-k){
                j++;
            }
            else if(j-i+1==n-k){
                mini=min(mini,sumi);
                sumi-=cardPoints[i];
                i++;
                j++;
            }
        }
        return sum-mini;
    }
};