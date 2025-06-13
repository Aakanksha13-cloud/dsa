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
    // void solve(TreeNode* root, queue<TreeNode*> &v){
    //     if(root==NULL){
    //         return;
    //     }
    //     v.push(root);
    //     solve(root->left,v);
    //     solve(root->right,v);
    // }
    void flatten(TreeNode* root) {
        // if(root==NULL)return;
        // queue<TreeNode*> v;
        // solve(root,v);
        // TreeNode* curr=v.front();
        // v.pop();
        // while(!v.empty()){
        //     TreeNode* next=v.front();
        //     v.pop();
        //     curr->left=NULL;
        //     curr->right=next;
        //     curr=next;
        // }
        // curr->left=NULL;
        // curr->right=NULL;
        // return;
        

        //imp approach
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
            TreeNode* predecessor=curr->left;
            while(predecessor->right){
                predecessor=predecessor->right;
            }
            
             predecessor->right=curr->right;
             curr->right=curr->left;
             curr->left=NULL;
        }
           curr=curr->right;
        }
    }
};