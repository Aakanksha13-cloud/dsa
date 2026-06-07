class Solution {
public:
    void solve(int i,int n, int k, int currcost,string& curr, vector<string>& ans){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        solve(i+1,n,k,currcost,curr,ans);
        curr.pop_back();
        if((curr.empty() || curr.back()!='1') && currcost+i<=k){
            curr.push_back('1');
            solve(i+1,n,k,currcost+i,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string curr="";
        solve(0,n,k,0,curr,ans);
        return ans;
    }
};