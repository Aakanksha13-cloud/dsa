class Solution {
public:
    void solve(int k, int target, vector<int>& curr,vector<vector<int>>& ans,int j){
        if(curr.size()==k){
            if(accumulate(curr.begin(),curr.end(),0)==target)ans.push_back(curr);
            return;
        }
        for(int i=j;i<=9;i++){
            curr.push_back(i);
            solve(k,target,curr,ans,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n<k)return ans;
        vector<int> curr;
        solve(k,n,curr,ans,1);
        return ans;
    }
};