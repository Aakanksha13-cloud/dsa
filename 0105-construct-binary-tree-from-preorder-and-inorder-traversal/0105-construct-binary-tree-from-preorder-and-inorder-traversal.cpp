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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preindex, int starti, int endi, int size,unordered_map<int,int>& m){
        if(preindex>=size)return NULL;
        if(starti>endi)return NULL;
        TreeNode* root= new TreeNode(preorder[preindex]);
        int element = m[preorder[preindex]];
        preindex++;
        root->left= solve(preorder,inorder,preindex,starti,element-1,size,m);
        root->right=solve(preorder,inorder,preindex,element+1,endi,size,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        int starti=0;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,preindex,starti,inorder.size()-1,inorder.size(),m);
    }
};