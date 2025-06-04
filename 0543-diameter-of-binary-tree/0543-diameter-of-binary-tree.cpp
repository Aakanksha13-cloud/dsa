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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l= maxDepth(root->left);
        int r=maxDepth(root->right);
        int height = max(l,r) +1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int combo = maxDepth(root->left)+maxDepth(root->right);
        int ans= max(combo,max(l,r));
        return ans;
    }
};