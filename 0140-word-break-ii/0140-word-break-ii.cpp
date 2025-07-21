class Solution {
public: 
    bool check(string& s, vector<string>& wordDict){
        for(auto i:wordDict){
            if(i==s)return true;
        }
        return false;
    }
    vector<string> rec(string& s, vector<string>& wordDict,int i){
        if(i==s.length()){
            return {""};
        }
        vector<string> ans;
        string word="";
        for(int j=i;j<s.length();j++){
            word+=s[j];
            if(check(word,wordDict)){
                auto recAns= rec(s,wordDict,j+1);
                for(auto eachRec:recAns){
                    string endPart;
                    if(eachRec.length()>0)endPart=" " + eachRec;
                    ans.push_back(word+endPart);
                }
            }
        }
        return ans;
       
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
       
        return  rec(s,wordDict,0);
    }
};