/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            vector<int>ans{-1,-1};
            // Less Then 3 nodes critical nodes possible nhi he.
            if(head-> next==nullptr || head==nullptr || head->next->next==nullptr){
                return ans;
            }
            //First off all we will make the Dummy Node
            ListNode* prev=head;
            ListNode* curr=head->next;
            int pos=1;
            int first=-1;
            int last=-1;
            int minDist=INT_MAX;
            while(curr->next !=nullptr){
                if(((curr->val>prev->val)&& (curr->val>curr->next->val)) ||((curr->val<prev->val)&&(curr->val<curr->next->val))){
                    // First Critical Point.
                    if(first==-1){
                        first=pos;
                        last=pos;
                    }
                    else{
                        minDist=min(minDist,pos-last);
                        last=pos;
                    }
                }
                prev=curr;
                curr=curr->next;
                pos++;
            }
            if(first==last){
                return ans;
            }
            int maxDist=last-first;
            ans[0]=minDist;
            ans[1]=maxDist;
            return ans;

    }
};