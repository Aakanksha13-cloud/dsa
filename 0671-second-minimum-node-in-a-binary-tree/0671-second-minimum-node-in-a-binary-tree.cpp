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
   void traverse(TreeNode* root, vector<int>& tree){
      if(root==NULL)return;
      traverse(root->left,tree);
      tree.push_back(root->val);
      traverse(root->right,tree);
   }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> tree;
        traverse(root,tree);
        sort(tree.begin(),tree.end());
        if(tree.size()==1)return -1;
        for(int i=1;i<tree.size();i++){
            if(tree[i]!=tree[i-1])return tree[i];
        }
        return -1;
    }
};