class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                for(int j=0;j<nums.size();j++){
                    if(nums[j]==2){
                        int curr=abs(i-j);
                        ans=min(ans,curr);
                    }
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};