class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> copy = nums;
        sort(copy.rbegin(),copy.rend());
        unordered_map<int,int> count;
        for(int i=0;i<k;i++){
            count[copy[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(count[nums[i]]>0){
               ans.push_back(nums[i]);
               count[nums[i]]--;
            }
            if(ans.size()==k)break;
        }
        return ans;
    }
};