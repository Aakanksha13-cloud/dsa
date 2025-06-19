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
    void update(TreeNode* root,vector<int> &arr,int &i){
        if(root==NULL)return;
        update(root->left,arr,i);
        root->val=arr[i];
        i++;
        update(root->right,arr,i);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return NULL;
        if(root->left==NULL && root->right==NULL)return root;
        vector<int> arr;
        inorder(root,arr);
        int n=arr.size();
        for(int i=n-2;i>=0;i--){
            arr[i]+=arr[i+1];
        }
        int index=0;
        update(root,arr,index);
        return root;
    }
};