class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        if(n==0)return 0;
    
        vector<vector<long long>> dp(n,vector<long long>(2,0));
        if(s[0]=='1'){
            dp[0][0]=nums[0];
            dp[0][1]=0;
        }
        for(int i=1;i<n;i++){
             long long bestiee= max(dp[i-1][0],dp[i-1][1]);
            if(s[i]=='1'){
                 dp[i][0]=bestiee+nums[i];
                long long next0=0;
                 if(s[i-1]=='1')next0=dp[i-1][1]+nums[i-1];
                else next0=dp[i-1][0]+nums[i-1];
                dp[i][1]=next0;
            }
            else{   
               dp[i][0]=bestiee;
                dp[i][1]=0;
            }  
        }
        long long ans=max(dp[n-1][0],dp[n-1][1]);
        return ans;
    }
};