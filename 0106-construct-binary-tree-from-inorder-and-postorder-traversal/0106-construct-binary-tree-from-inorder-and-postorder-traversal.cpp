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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &pindex, int s, int e, int size, unordered_map<int,int> &m){
        if(pindex<0)return NULL;
        if(s>e)return NULL;
        TreeNode* root = new TreeNode(postorder[pindex]);
        int element= m[postorder[pindex]];
        pindex--;
        root->right= solve(inorder,postorder,pindex,element+1,e,size,m);
        root->left=solve(inorder,postorder,pindex,s,element-1,size,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int size =inorder.size();
        int pindex =size-1;
        int s=0;
        int e = size-1;
        return solve(inorder, postorder, pindex,s,e,size,m);
    }
};