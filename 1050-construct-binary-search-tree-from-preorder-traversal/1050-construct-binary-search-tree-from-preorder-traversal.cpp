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
    int i=0;
    TreeNode* solve(vector<int>& preorder, int maxVal){
        if(i==preorder.size()|| preorder[i]>= maxVal)return NULL;
        int rootVal=preorder[i];
        
        TreeNode* root=new TreeNode(rootVal);
        i++;
        root->left=solve(preorder,rootVal);
        root->right=solve(preorder,maxVal);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return solve(preorder,INT_MAX);
    }
};