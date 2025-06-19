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
        string curr=to_string(root->val);
        string l=serialize(root->left);
        string r=serialize(root->right);
        return curr+","+l+","+r;
    }

    // Decodes your encoded data to tree.
    TreeNode* solve(vector<string> &v,int &i){
        if(v[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(v[i]));
        i++;
        root->left= solve(v,i);       
        root->right=solve(v,i);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        vector<string> v;
        while(getline(ss,word,',')){
            v.push_back(word);
        }
        int i=0;
        return solve(v,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;