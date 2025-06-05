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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int l = height(root->left);
        int r= height(root->right);
        int ans = (max(l,r)+1);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l-r)>1)return false;
        // if(!isBalanced(root->left))return false;
        // if(!isBalanced(root->right))return false;
        return isBalanced(root->left)&&isBalanced(root->right) ;
    }
};