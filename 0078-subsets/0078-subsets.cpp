class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr, int i){
        if(i==nums.size())return;
        int num=nums[i];
        //include
        curr.push_back(nums[i]);
        ans.push_back(curr);
        solve(nums,ans,curr,i+1);
        //exclude
        curr.pop_back();
        solve(nums,ans,curr,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr={};
        ans.push_back(curr);
        solve(nums,ans,curr,0);
        return ans;
    }
};