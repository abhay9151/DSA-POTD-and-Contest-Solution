class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int b1 = __builtin_popcount(num2);
        int b2 = __builtin_popcount(num1);

        if (b1 == b2)
            return num1;

        if (b1 < b2) {
            for (int i = 0; i < 31; i++) {
                if ((num1 >> i) & 1) {
                    num1 &= ~(1 << i);
                    b1++;

                    if (b1 == b2)
                        return num1;
                }
            }
        } else {
            int ans = num1;
            b1 -= b2;

            for (int i = 0; i < 31; i++) {
                if (((num1 >> i) & 1) == 0) {
                    ans |= (1 << i);
                    b1--;

                    if (b1 == 0)
                        return ans;
                }
            }
        }

        return num1;
    }
};