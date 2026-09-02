class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int odcount=0;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                odcount++;
            }
        }
        bool alleven=(odcount==0 ||odcount>=2);
        bool allodd=(odcount>=1);
        return alleven||allodd;
    }
};