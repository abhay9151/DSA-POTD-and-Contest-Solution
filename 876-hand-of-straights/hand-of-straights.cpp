class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int >mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
        int start;
        for(auto it : mp) {
        start = it.first;
        break;
        }
        for(int i=0;i<groupSize;i++){
            int num=start+i;
            if(mp.find(num)==mp.end()){
                return false;
            }
            mp[num]--;
            if(mp[num]==0){
                mp.erase(num);
            }

        }
    }
        return true;
    }
};