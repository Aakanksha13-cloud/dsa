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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        if(root==NULL){
            return false;
        } 
        sum = sum + root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum == targetSum)return true;
            else return false;
        }
        bool l =hasPathSum(root->left,targetSum-sum);
        bool r = hasPathSum(root->right,targetSum-sum);
        return l||r;
    }
};