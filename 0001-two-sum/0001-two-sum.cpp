class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //O(n2)
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }

        //O(n)

        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            
            int tofind= target-nums[i];
            if(m.find(tofind)!=m.end() && m[tofind]!=i ){ //O(1) me search
                ans.push_back(i);
                ans.push_back(m[tofind]);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};