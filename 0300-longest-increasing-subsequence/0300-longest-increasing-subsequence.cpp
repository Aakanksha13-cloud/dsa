class Solution {
public:
    int solve(vector<int>& nums,int lastIndex,int i,vector<vector<int>> &dp){
        if(i>=nums.size())return 0;
        if(dp[lastIndex+1][i]!=-1)return dp[lastIndex+1][i];
        int include=0;
        if(lastIndex==-1||nums[i]>nums[lastIndex])include=1+solve(nums,i,i+1,dp);
        int exclude = solve(nums,lastIndex,i+1,dp);
        dp[lastIndex+1][i]= max(include,exclude);
        return dp[lastIndex+1][i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int last = -1;
        int n=nums.size();
        int i=0;
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return solve(nums,last,i,dp);
    }
};