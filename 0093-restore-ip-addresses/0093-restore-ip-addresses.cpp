class Solution {
public:
    void solve(string s,vector<string>& ans,string curr, int i, int parts){
        if(i==s.length() && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(i>=s.length() || parts>=4){
            return;
        }
        for(int len=1; len<=3 && i+len<=s.length();len++){
            string currpart=s.substr(i,len);
            if(currpart.length()>1 && currpart[0]=='0')continue;
            if(stoi(currpart)>255)continue;
            solve(s,ans,curr+currpart+'.',i+len,parts+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr="";
        solve(s,ans,curr,0,0);
        return ans;
    }
};