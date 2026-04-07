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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int level=q.size();
            vector<int> curr;
            for(int i=0;i<level;i++){
                TreeNode* node=q.front();
                int val= node->val;
                q.pop();
                curr.push_back(val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            int n=curr.size();
            ans.push_back(curr[n-1]);
        }
        return ans;
    }
};