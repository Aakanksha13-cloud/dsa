class Solution {
public:
    bool check(string s, vector<string>& wordDict){
        for(auto i:wordDict){
            if(s==i)return true;
        }
        return false;
    }
    bool rec(string& s, vector<string>& wordDict,int i,vector<int>& dp){
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        string word="";
        bool ans=false;
        for(int j=i;j<s.length();j++){
            word+=s[j];
            if(check(word,wordDict)){
                ans= ans||rec(s,wordDict,j+1,dp);              
            }
        }
        dp[i]=ans;
        return dp[i];
    }
    bool solveTab(string s, vector<string>& wordDict){
         int n= s.length();
         vector<int> dp(n+1,-1);
         dp[n]=1;
         for(int i=n-1;i>=0;i--){
            string word="";
         bool ans=false;
         for(int j=i;j<s.length();j++){
            word+=s[j];
            if(check(word,wordDict)){
                ans= ans||dp[j+1];              
            }
        }
        dp[i]=ans;
         }
         return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       
        //return rec(s,wordDict,0);
        // int n= s.length();
        //  vector<int> dp(n+1,-1);
        //  return rec(s,wordDict,0,dp);
        return solveTab(s,wordDict);

    }
};