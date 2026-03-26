class Solution {
public:
void solve(vector<int>& nums,set<vector<int>>& ans,vector<int>& curr, int i){
        if(i==nums.size())return;
        int num=nums[i];
        //include
        curr.push_back(nums[i]);
        ans.insert(curr);
        solve(nums,ans,curr,i+1);
        //exclude
        curr.pop_back();
        solve(nums,ans,curr,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> curr={};
        ans.insert(curr);
        solve(nums,ans,curr,0);
        for(auto st:ans){
            result.push_back(st);
        }
        
        return result;
    }
};