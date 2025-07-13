class Solution {
public:
    // int maxMoneyTD(vector<int>& nums, int index,vector<int>& dp){
    //    if(index >= nums.size()){
    //       return 0;
    //    }
    //    if(dp[index]!=-1)return dp[index];
       
    //    int include = nums[index]+ maxMoneyTD(nums,index+2,dp);
    //    int exclude = 0+ maxMoneyTD(nums,index+1,dp);
    //    dp[index] = max(include, exclude);
    //    return dp[index];
    // }
    int rob(vector<int>& nums) {
        // int i =0;
        // int n=nums.size();
        // vector<int> dp(n+1,-1);
        // return maxMoneyTD(nums,i,dp);
        int n = nums.size();
        int next1=0;
        int next2=0;
        for(int i=n-1;i>=0;i--){
           int include = nums[i]+next2;
           int exclude = next1;
           int curr=max(include,exclude);
           next2=next1;
           next1=curr;
        }
        return next1;
    }
};