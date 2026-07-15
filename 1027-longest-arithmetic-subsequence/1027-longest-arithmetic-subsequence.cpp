class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n); //for every subseq ending at i, max len with diff d
        int ans=2;
        for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
              int diff=nums[i]-nums[j];
              if(dp[j].count(diff)){ //check if diff n subseq already exists
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1); //extending subseq till i
              }
              else dp[i][diff]=max(dp[i][diff],2);
              ans= max(ans,dp[i][diff]);
           }
        }
        return ans;
    }
};