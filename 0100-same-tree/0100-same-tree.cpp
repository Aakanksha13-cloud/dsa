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
    // void solve(TreeNode* p,vector<TreeNode*> &traverse){
    //     if(p==NULL){
    //         traverse.push_back(nullptr);
    //         return;
    //     }
    //     traverse.push_back(p);
    //     solve(p->left,traverse);
    //     solve(p->right,traverse);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    //    vector<TreeNode*> tree1;
    //    vector<TreeNode*> tree2;
    //    solve(p,tree1);
    //    solve(q,tree2);
    //    if(tree1.size()!=tree2.size())return false;
    //    for(int i=0;i<tree1.size();i++){
    //     if(tree1[i]==NULL && tree2[i]!=NULL)return false;
    //     if(tree2[i]==NULL && tree1[i]!=NULL)return false;
    //     if(tree1[i] && tree2[i]&& (tree1[i]->val!=tree2[i]->val))return false;
    //    }
    //    return true;
        if(p==NULL && q==NULL)return true;
        else if(p==NULL || q==NULL)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};