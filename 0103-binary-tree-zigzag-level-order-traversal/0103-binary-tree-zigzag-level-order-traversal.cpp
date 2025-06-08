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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int zigzag =0;
        while(!q.empty()){
            int level=q.size();
            vector<int> currlevel;
            for(int i=0;i<level;i++){
                TreeNode* front=q.front();
                q.pop();
                currlevel.push_back(front->val);
               
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                
            }
            if(zigzag%2!=0)reverse(currlevel.begin(),currlevel.end());
            ans.push_back(currlevel);
            zigzag+=1;
        }
        return ans;
    }
};