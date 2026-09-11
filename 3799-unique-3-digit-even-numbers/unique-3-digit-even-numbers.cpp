class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int>ans;
        vector<int>mp(10,0);
        for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        for(int i=1;i<=9;i++){
            if(mp[i]==0)continue;
            mp[i]--;
            for(int j=0;j<=9;j++){
                if(mp[j]==0)continue;
                mp[j]--;
                for(int k=0;k<=8;k+=2){
                if(mp[k]==0)continue;
                mp[k]--;
                int digit=i*100+j*10+k*1;
                if(digit>=100 && digit%2==0){
                        ans.insert(digit);
                }
                mp[k]++;
                }
            mp[j]++;
            }
        mp[i]++;
        }
        return ans.size();
    }
};


// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         int n=digits.size();
//         set<int>st;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 for(int k=0;k<n;k++){
//                     if(i==j || j==k || i==k){
//                         continue;
//                     }
//                     int digit=digits[i]*100+digits[j]*10+digits[k]*1;
//                     if(digit>=100 && digit%2==0){
//                         st.insert(digit);
//                     }
//                 }
//             }
//         }
//         return st.size();
//     }
// };