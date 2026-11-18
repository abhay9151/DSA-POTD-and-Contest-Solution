class Solution {
public:
    string digitSum(string s, int k) {
        int sz, i, sum;
        string temp;

        while(s.size() > k){
            temp = "";
            i = 0, sz = s.size(), sum = 0;

            while(i < sz){
                sum += s[i] - '0';

                if((i + 1) % k == 0) temp += to_string(sum), sum = 0;

                i++;
            }

            if(s.size() % k) temp += to_string(sum);

            s = temp;
        }

        return s;
    }
};