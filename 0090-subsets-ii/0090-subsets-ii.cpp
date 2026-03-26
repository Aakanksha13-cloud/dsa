class Solution {
public:
// void solve(vector<int>& nums,set<vector<int>>& ans,vector<int>& curr, int i){
//         if(i==nums.size())return;
//         int num=nums[i];
//         //include
//         curr.push_back(nums[i]);
//         ans.insert(curr);
//         solve(nums,ans,curr,i+1);
//         //exclude
//         curr.pop_back();
//         solve(nums,ans,curr,i+1);
//     }
void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int index) {
    result.push_back(curr);

    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i-1]) continue;

        curr.push_back(nums[i]);
        solve(nums, result, curr, i + 1);
        curr.pop_back();
    }
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        //set<vector<int>> ans;
        vector<int> curr={};
        //ans.insert(curr);
        solve(nums,result,curr,0);
        // for(auto st:ans){
        //     result.push_back(st);
        // }
        
        return result;
    }
};