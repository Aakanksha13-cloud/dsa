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
    string tree2str(TreeNode* root) {
        if(root==NULL)return "";
        string curr= to_string(root->val);
        string l=tree2str(root->left);
        string r=tree2str(root->right);
        if(l==""&&r=="")
            return curr;
        else if(l!="" && r=="")
            return curr + "("+l+")";
        else if(l=="" && r!="")
            return curr + "()("+r+")";
        else return curr+"("+l+")("+r+")";
        
    }
};