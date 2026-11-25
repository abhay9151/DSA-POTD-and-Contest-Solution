class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long count=0;
        long long odd=0;
        long long even=1;
        long long mod = 1e9 + 7;
        vector<long long>prefixsum(n);
        prefixsum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=arr[i]+prefixsum[i-1];
        }
        for(int i=0;i<n;i++){
            if(prefixsum[i]%2==0){
                even++;
                count+=odd;
            }
            else{
                odd++;
                count+=even;
            }
        }
        return count % mod;
    }
};