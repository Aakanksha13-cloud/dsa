class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int opt1=nums[i]+solve(nums,dp,i+2);
        int opt2=solve(nums,dp,i+1);
        dp[i]=max(opt1,opt2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,dp,0);
    }
};