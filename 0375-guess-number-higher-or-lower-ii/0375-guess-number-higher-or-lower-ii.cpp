class Solution {
public:
    int rec(int s,int e,vector<vector<int>>& dp){
        if(s>=e)return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            ans=min(ans,i+max(rec(i+1,e,dp),rec(s,i-1,dp)));
        }
        return dp[s][e]=ans;
    }
    int solveTab(int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int s=n;s>=1;s--){
            for(int e=s;e<=n;e++){
               if(s>=e)continue;
               else{
                 int ans=INT_MAX;
        for(int i=s;i<e;i++){
            ans=min(ans,i+max(dp[i+1][e],dp[s][i-1]));
        }
        dp[s][e]=ans;
               }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return rec(1,n,dp);
        return solveTab(n);
    }
};