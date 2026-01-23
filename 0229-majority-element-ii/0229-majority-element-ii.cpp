class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto f:freq){
            if(f.second>(n/3))ans.push_back(f.first);
        }
        return ans;
    }
};