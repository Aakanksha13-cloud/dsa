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
    void inorder(TreeNode* root,vector<int>& arr){
        if(root==NULL)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        TreeNode* ans=new TreeNode(arr[0]);
        TreeNode* curr=ans;
        int i=1;
        while(i<arr.size()){
            curr->right= new TreeNode(arr[i]);
            curr=curr->right;
            i++;
        }
        return ans;
    }
};