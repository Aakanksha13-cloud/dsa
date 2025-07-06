class TrieNode{
   public:
   char val;
    unordered_map<char,TrieNode*> children;
    bool isTerminal;
    TrieNode(char data){
        val=data;
        isTerminal=false;
    }
};

    void insertWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        char ch=word[0];
        TrieNode* child;
        //present
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        //absent
        else{
            child = new TrieNode(ch);
            root->children[ch]= child;
        }
        insertWord(child,word.substr(1));
    }
    bool searchWord(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        char ch=word[0];
        TrieNode* child;
        //present
        if(root->children.find(ch)!=root->children.end()){
           child=root->children[ch];
        }
        //absent
        else{
            return false;
        }
        bool recKaAns = searchWord(child,word.substr(1));
        return recKaAns;
    }
    bool searchWithPrefix(TrieNode* root,string word){
        if(word.length()==0)return true;
        char ch=word[0];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else return false;
        bool recKaAns = searchWithPrefix(child,word.substr(1));
        return recKaAns;
    }

class Trie {
public:
    TrieNode* root;
    Trie() {
       root= new TrieNode('-'); 
    }
    
    void insert(string word) {
       insertWord(root,word);
    }
    
    bool search(string word) {
       return searchWord(root,word); 
    }
    
    bool startsWith(string prefix) {
        return searchWithPrefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */