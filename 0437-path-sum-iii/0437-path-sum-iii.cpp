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
    int ans =0;
    void solve(TreeNode* root, long long targetSum){    
        if(root==NULL)return;
        if(targetSum==root->val)ans+=1;
        solve(root->left,targetSum-root->val);
        solve(root->right,targetSum-root->val);
       
    }
    int pathSum(TreeNode* root, long long targetSum) {
       if(root!=NULL){
          solve(root,targetSum);
          pathSum(root->left,targetSum);
          pathSum(root->right,targetSum);
       } 
        return ans;
    }
};