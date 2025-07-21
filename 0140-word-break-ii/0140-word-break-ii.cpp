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

    vector<string> recBU(string& s, vector<string>& wordDict,int i, unordered_map<int,vector<string>>& dp){
        if(i==s.length()){
            return {""};
        }
        if(dp.find(i)!=dp.end())return dp[i];
        vector<string> ans;
        string word="";
        for(int j=i;j<s.length();j++){
            word+=s[j];
            if(check(word,wordDict)){
                auto recAns= recBU(s,wordDict,j+1,dp);
                for(auto eachRec:recAns){
                    string endPart;
                    if(eachRec.length()>0)endPart=" " + eachRec;
                    ans.push_back(word+endPart);
                }
            }
        }
        return dp[i]= ans;
       
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return  rec(s,wordDict,0);
        unordered_map<int,vector<string>> dp;
        return  recBU(s,wordDict,0,dp);
    }
};