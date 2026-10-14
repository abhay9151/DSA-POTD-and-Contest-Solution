// In this question the approach used is this beacause we have to maximise the score the digit first we should use should be the the '9'. Add as many of the 9  that we can add to maximiase the sum.Now add the remainder in the string .If left with the length of num then add zero to rest of the place.

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string s="";
        for(int i=0;i<num;i++){
            if(sum>=9){
                s.push_back('9');
                sum-=9;
            }
            else{
                s.push_back('0'+sum);// automatically add kardega elements in the s in place of left out num size.
                sum=0;
            }
        }
        return s;
    }
};