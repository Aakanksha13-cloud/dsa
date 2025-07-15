class Solution {
public:
   int rec(int n){
    if(n==0){
        return 1;
    }
    int option1=0;
    if(n-1>=0){
        option1=rec(n-1);
    }
    int option2=0;
    if(n-1>=0){
        option2=rec(n-2);
    }
    return option1+option2;
   }


    int solveMem(int n, vector<int>& dp){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1)return dp[n];
    int option1=0;
    if(n-1>=0){
        option1=solveMem(n-1,dp);
    }
    int option2=0;
    if(n-2>=0){
        option2=solveMem(n-2,dp);
    }
    dp[n]= option1+option2;
    return dp[n];
   }
    
    int climbStairs(int n) {
    //   return rec(n);
      
       vector<int> dp(n+1,-1);
       return solveMem(n,dp);
    }
};