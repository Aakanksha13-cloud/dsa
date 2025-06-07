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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preindex, int starti, int endi, int size){
        if(preindex>=size)return NULL;
        if(starti>endi)return NULL;
        TreeNode* root= new TreeNode(preorder[preindex]);
        int element;
        for(int i=starti;i<=endi;i++){
            if(inorder[i]==preorder[preindex]){
                element =i;
                break;
            }
        }
        preindex++;
        root->left= solve(preorder,inorder,preindex,starti,element-1,size);
        root->right=solve(preorder,inorder,preindex,element+1,endi,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        int starti=0;
        return solve(preorder,inorder,preindex,starti,inorder.size()-1,inorder.size());
    }
};