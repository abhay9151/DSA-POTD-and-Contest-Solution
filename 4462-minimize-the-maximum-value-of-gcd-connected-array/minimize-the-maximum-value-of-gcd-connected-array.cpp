class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(n == 1) return value;
        if(value == 1) return -1;
        long long p = value;
        for(long long i=2;i<=value/i;i++) {
            if(value%i == 0) {
                p = i;
                break;
            }
        }
        if(value-p<2LL*index) {
            return -1;
        }
        if(index == n-1) {
            return value;
        }
        return value+p+2LL*(n-index-2);
    }
};