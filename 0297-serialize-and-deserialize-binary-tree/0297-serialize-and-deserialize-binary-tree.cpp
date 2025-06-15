/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "N";
        string curr= to_string(root->val);
        string l=serialize(root->left);
        string r=serialize(root->right);
        return curr+","+l+","+r;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* solve(queue<string>& q){
        if(q.empty())return NULL;
        if(q.front()=="N"){
            q.pop();
            return NULL;
        }
        TreeNode* curr=new TreeNode(stoi(q.front()));//tree allows only int values, therefore stoi
        q.pop();
        curr->left = solve(q);
        curr->right=solve(q);
        return curr;
        
}
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string str;
        queue<string> q;
        while(getline(ss,str,',')){
            q.push(str);
        }
        return solve(q);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));