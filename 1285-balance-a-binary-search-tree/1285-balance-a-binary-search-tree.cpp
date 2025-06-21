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
    void inorder(TreeNode* root,vector<int> &arr){
        if(root==NULL)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* solve(vector<int> &arr,int s, int e){
        if(s>e || s<0 || e>=arr.size())return NULL;
        int mid= s+(e-s)/2;
        TreeNode* root= new TreeNode(arr[mid]);
        root->left=solve(arr,s,mid-1);
        root->right=solve(arr,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return root;
        vector<int> arr;
        inorder(root,arr);
        return solve(arr,0,arr.size()-1);
    }
};