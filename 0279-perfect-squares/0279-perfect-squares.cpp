class Solution {
public:
    int solveMem(int n,vector<int>& dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            ans=min(ans,1+solveMem(n-sq,dp));
            dp[n]=ans;
        }
        return dp[n];
        
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};