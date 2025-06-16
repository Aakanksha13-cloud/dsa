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
    int getMax(TreeNode* root){
        if(root==NULL)return -1;
        while(root->right){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        if(root==NULL)return NULL;
        if(root->val<key)root->right=deleteNode(root->right,key);
        else if(root->val>key)root->left=deleteNode(root->left,key);
        else{
          if(!root->left && !root->right){
            delete root;
            return NULL;
           
        }
        else if(!root->left && root->right){
            TreeNode* rightChild=root->right;
            root->right=NULL;
            delete root;
            return rightChild;
           
        }
        else if(root->left && !root->right){
            TreeNode* leftChild=root->left;
            root->left=NULL;
            delete root;
            return leftChild;
           
        }
        else{
           int minVal=getMax(root->left);
           root->val=minVal;
           root->left=deleteNode(root->left,minVal);
           return root;
        }
        }
        return root;
        
    }
};