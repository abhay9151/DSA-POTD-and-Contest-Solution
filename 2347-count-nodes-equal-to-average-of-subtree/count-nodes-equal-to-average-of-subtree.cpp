/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int> pre(TreeNode* r){
        if(!r) return {0,0};
        auto left=pre(r->left);
        auto right=pre(r->right);
        int avg=(left.first+right.first+r->val)/(left.second+right.second+1);
        if(avg==r->val) ans++;
        return {left.first+right.first+r->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        pre(root);
        return ans;
    }
};