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
    bool solve(TreeNode* root, long long int minval, long long int maxval){
        if(root==NULL)return true;
        if(root->val<=minval || root->val>=maxval)return false;
        return solve(root->left,minval,root->val)&& solve(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root,LONG_MIN,LONG_MAX);//long_min,long_max have larger range than intmin ,intmax
    }
};