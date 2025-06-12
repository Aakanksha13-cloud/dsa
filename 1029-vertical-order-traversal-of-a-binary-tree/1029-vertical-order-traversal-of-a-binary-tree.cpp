
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
   struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int i : v)
            hash ^= hash * 31 + std::hash<int>()(i);
        return hash;
    }
};
 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       queue<pair<TreeNode*,vector<int>>> q;
       q.push({root,{0,0}});
       unordered_map<vector<int>,vector<int>, VectorHash> m;//set custom operator
       int minc=INT_MAX;
       int maxc=INT_MIN;
       int maxr=INT_MIN;
       while(!q.empty()){
        auto front= q.front();
        q.pop();
        TreeNode* n = front.first;
        vector<int> v= front.second;
        int r=v[0];
        int c=v[1];
        minc=min(minc,c);
        maxc=max(maxc,c);
        maxr=max(maxr,r);
        m[v].push_back(n->val);//append like this else it will overwrite prev values
        if(n->left)q.push({n->left,{r+1,c-1}});
        if(n->right)q.push({n->right,{r+1,c+1}});
       }
       vector<vector<int>> ans;
       for(int i=minc;i<=maxc;i++){
        vector<int> curr;
        for(int j=0;j<=maxr;j++){
            vector<int> values=m[{j,i}];
            sort(values.begin(),values.end());
            curr.insert(curr.end(),values.begin(),values.end());//equi to for loop for values,helps to add multiple values to vector at a certain pos
        }
        ans.push_back(curr);
       }
       return ans;
    }
};