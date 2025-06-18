/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(root->val<p->val&&root->val<q->val){
            TreeNode* r=lowestCommonAncestor(root->right,p,q);
            if(r!=NULL)return r;
        }
        else if(root->val>p->val&&root->val>q->val){
            TreeNode* l=lowestCommonAncestor(root->left,p,q);
            if(l!=NULL)return l;
        }
        return root;
    }
};