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
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans,vector<int>& present){
        if(root==NULL){
            return;
        } 
        present.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(root->val == targetSum){
               
                ans.push_back(present);
            } 
        }
       
        solve(root->left,targetSum-root->val,ans,present);
        // present.pop_back();
        solve(root->right,targetSum-root->val,ans,present);
        present.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> present;
        if(root==NULL)return {};
        solve(root,targetSum,ans,present);
        return ans;
    }
};