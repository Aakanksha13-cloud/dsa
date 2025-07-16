class Solution {
public:
    bool rec(int n,vector<int>& dp){
      if(n==1)return false;
      if(dp[n]!=-1)return dp[n];
      for(int i=n-1;i>0;i--){
        if(n%i==0){
            bool recKaAns= rec(n-i,dp);
            if(!recKaAns){
                dp[n]=true;
                return dp[n];
            }
        }
      }
      return dp[n]=false;
    }
    bool divisorGame(int n) {
       vector<int> dp(n+1,-1);
       return rec(n,dp);
    }
};