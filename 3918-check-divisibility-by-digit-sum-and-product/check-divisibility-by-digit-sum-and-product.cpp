class Solution {
public:
    bool checkDivisibility(int n) {
        int a = n;
        int sum = 0;
        int product = 1;
        while(a > 0) {
            sum +=a%10;
            product*=a%10;
            a = a / 10;
        }
        return n % (sum + product) == 0;
    }
};