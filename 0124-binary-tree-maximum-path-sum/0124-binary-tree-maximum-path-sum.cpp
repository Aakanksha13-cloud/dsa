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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        int x=root->val;
        int l=0;
        if(root->left)l=solve(root->left);
        if(l<0)l=0;
        int r=0;
        if(root->right)r=solve(root->right);
        if(r<0)r=0;
        ans = max(ans,x+l+r);
        return x+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        //3 opt- diameter, left, right
        solve(root);
        return ans;
    }
};