class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        if(n < 1000)return 0;
        for(int i = 1000; i <= n; i++) {
            string ans = "";
            int temp = i;
            while(temp > 0) {
                ans += char((temp % 10) + '0');
                temp = temp / 10;
            }
            reverse(ans.begin(), ans.end());
            if(ans.length() >= 4) {
                count += (ans.length() - 1) / 3;
            }
        }
        return count;
    }
};