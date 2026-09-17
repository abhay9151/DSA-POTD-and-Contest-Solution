//Time Complexity o(N) in this question hamne sirf itna kiya he apne se pahle index ke sabhi subraaay jinka sum==target he usko store karle. Hamne do subarray nikal na he jiska sum target ke equal he top local minimum previous ko leke aor global (overall) minimum nikalte raho.
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currsum=0;
        int result=INT_MAX;
        int len=-1;
        int best=INT_MAX;
        vector<int>minlenbeforenow(n,INT_MAX);
        while(j<n){
            currsum+=arr[j];
            while(currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                len=j-i+1;
                if(i>0 && minlenbeforenow[i-1]!=INT_MAX){
                    result=min(result,len+minlenbeforenow[i-1]);
                }
                best=min(best,len);
            }
            minlenbeforenow[j]=best;
            j++;
        }
        if(result==INT_MAX){
            return -1;
        }
        return result;
    }
};