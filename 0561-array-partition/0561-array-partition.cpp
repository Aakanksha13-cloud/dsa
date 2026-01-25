class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=nums[0];
        int i=2;
        while(i<nums.size()){
            ans+=nums[i];
            i+=2;
        }
        return ans;
    }
};