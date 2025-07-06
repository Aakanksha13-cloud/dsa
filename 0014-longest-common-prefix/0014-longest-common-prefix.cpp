class TrieNode{
    public:
    char val;
    unordered_map<char,TrieNode*> children;
    bool isTerminal;
    TrieNode(char data){
        val=data;
        isTerminal = false;
    }
};
void insert(TrieNode* root, string word){
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }
    char ch=word[0];
    TrieNode* child;
    if(root->children.find(ch)!=root->children.end()){
        child=root->children[ch];
    }
    else{
        child = new TrieNode(ch);
        root->children[ch]=child;
    }
    insert(child,word.substr(1));
}
class Solution {
public:
    void solve(TrieNode* root, string& ans){
        if(root->isTerminal == true)return;
        TrieNode* child;
        if(root->children.size()==1){
            for(auto i:root->children){
                char ch = i.first;
                ans.push_back(ch);
                child = i.second;
            }
        }
        else return;
        solve(child,ans);
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(auto str:strs){
            insert(root,str);
        }
        string ans="";
        solve(root,ans);
        return ans;
        // string ans;
        // int i = 0;
        // while(true){
        //     char curr_ch = 0;
        //     for(auto str:strs){
        //         if(i>= str.size()){
        //             curr_ch =0;
        //             break;
        //         }
        //         if(curr_ch == 0){
        //             curr_ch = str[i];
        //         }
        //         if(curr_ch != str[i]){
        //              curr_ch =0;
        //             break;
        //         }
        //     }
        //     if(curr_ch == 0)
        //       break;

        //     ans.push_back(curr_ch);
        //     i++;
        // }
        // return ans;
    }
};