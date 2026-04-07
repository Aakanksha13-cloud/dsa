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
    
    
    void solve(TreeNode* root,int maxval,int &ans){
        if(root->val>=maxval)ans++;
        maxval=max(maxval,root->val);
        if(root->left)solve(root->left,maxval,ans);
        if(root->right)solve(root->right,maxval,ans);
    }
    int goodNodes(TreeNode* root) {
        int maxval=INT_MIN;
        int ans=0;
        solve(root,maxval,ans);
        return ans;
    }
};