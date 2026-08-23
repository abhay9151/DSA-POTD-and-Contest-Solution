class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int right_sum=0;
        int left_sum=0;
        int qnmarksright=0;
        int qnmarksleft=0;
        int i=0;
        int j=num.size();
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
            qnmarksright++; 
            }
            else{
            right_sum+=num[i]-'0';
            }
        }
        for(int j=n/2;j<n;j++){
            if(num[j]=='?'){
            qnmarksleft++; 
        }
            else{
            left_sum+=num[j]-'0';// nums[j] is the charcter not integer.
            }
        }
        if((qnmarksleft+qnmarksright)%2!=0){
            return true;
        }
        if(2*right_sum+9*(qnmarksright)==2*left_sum+9*(qnmarksleft)){
        return false;
        }
        else{
            return true;
        }
    }
};