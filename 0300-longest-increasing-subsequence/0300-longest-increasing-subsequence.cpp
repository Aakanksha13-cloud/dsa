class Solution {
public:
    int solveTopDown(vector<int>& nums,int lastIndex,int i,vector<vector<int>> &dp){
        if(i>=nums.size())return 0;
        if(dp[lastIndex+1][i]!=-1)return dp[lastIndex+1][i];
        int include=0;
        if(lastIndex==-1||nums[i]>nums[lastIndex])include=1+solveTopDown(nums,i,i+1,dp);
        int exclude = solveTopDown(nums,lastIndex,i+1,dp);
        dp[lastIndex+1][i]= max(include,exclude);
        return dp[lastIndex+1][i];
    }
    int solveTab(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1||nums[curr]>nums[prev])include=1+dp[curr+1][curr+1];
                int exclude = dp[prev+1][curr+1];
                dp[prev+1][curr]= max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        // int lastIndex = -1;
        // int n=nums.size();
        // int i=0;
        // vector<vector<int>> dp(n+1,vector<int>(n,-1));
        // return solveTopDown(nums,lastIndex,i,dp);
        return solveTab(nums);
    }
};