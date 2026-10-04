//First, calculate the sum of the first k cards assuming all are taken from the left.
// Then, move one card at a time from the left end to the right end, updating left and right sums accordingly.
// After each move, compute the total of lsum + rsum and keep track of the maximum value found.
// Finally, return this maximum sum as the highest score possible by choosing k cards from both ends.


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int  lsum=0;int rsum=0; int maxsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];// max length ki ak window lena he 
        }
            maxsum=lsum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};