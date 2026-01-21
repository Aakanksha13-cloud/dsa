class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)continue;
            int currans=0;
            while(i<nums.size() && nums[i]==1  ){
               currans++;
               ans=max(ans,currans);
               i++;
            }
        }
        return ans;
    }
};