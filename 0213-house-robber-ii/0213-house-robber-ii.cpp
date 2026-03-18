class Solution {
public:
    int rec(vector<int>& arr,int i,vector<int>& dp){
      if(i>=arr.size())return 0;
      if(dp[i]!=-1)return dp[i];
      int inc=arr[i]+rec(arr,i+2,dp);
      int exc=rec(arr,i+1,dp);
      dp[i]=max(inc,exc);
      return dp[i];
  }

int solve(vector<int> nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return rec(nums,0,dp);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        return max(solve(v1),solve(v2));
        
    }
};