class Solution {
public:
    bool isPalindromic(string s) {
        vector<int>arr;
       for(int i=0;i<s.size();i++){
            int a=(int)s[i];
            arr.push_back(a);
       } 
       reverse(arr.begin(),arr.end());
       string temp="";
       for(int i=0;i<arr.size();i++){
            temp += bitset<8>(arr[i]).to_string();
       }
       int k=0;
       int l=temp.size()-1;
       bool is_palindrome=false;
       while(k<l){
            if(temp[k]!=temp[l]){
                is_palindrome=true;
            }
            k++;
            l--;
       }
       return !is_palindrome;
    }
};