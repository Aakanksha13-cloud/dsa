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
    vector<TreeNode*> ans;
    unordered_map<string,int> m;
    string preorder(TreeNode* root){
        if(root==NULL)return "N";
       
        string curr=to_string(root->val);
        string l=preorder(root->left);
        string r=preorder(root->right);
        string s= curr +","+l+","+r;
        if(m.find(s)!=m.end()){
            if(m[s]==1)ans.push_back(root);
            m[s]++;
        }
        else m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       preorder(root);
        return ans;
    }
};