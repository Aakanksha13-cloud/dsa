class Solution {
public:
    int solve(vector<int>& cost,int i){
       if(i>=cost.size()){
        return 0;
       }
       int climbOne= cost[i] + solve(cost,i+1);
       int climbTwo=cost[i] + solve(cost,i+2);
       return min(climbOne,climbTwo);
    }

    int solveMem(vector<int>& cost,int i,vector<int>& dp){
        if(i>=cost.size()){
        return 0;
       }
       if(dp[i]!=-1)return dp[i];
       int climbOne= cost[i] + solveMem(cost,i+1,dp);
       int climbTwo=cost[i] + solveMem(cost,i+2,dp);
       dp[i]= min(climbOne,climbTwo);
       return dp[i];
    }

    int solveTab(vector<int>& cost){
        int n=cost.size();
        vector<int> dp(n+2,0);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--){
            int climbOne= cost[i] + dp[i+1];
            int climbTwo=cost[i] + dp[i+2];
            dp[i]= min(climbOne,climbTwo);
        }
        return min(dp[0],dp[1]);
    }
    
    int SpaceOpti(vector<int>& cost){
        int n=cost.size();
        int prev1=0;
        int prev2=0;
        for(int i=n-1;i>=0;i--){
            int currCost= cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=currCost;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // int zeroindex=solve(cost,0);
        // int oneIndex=solve(cost,1);
        // return min(zeroindex,oneIndex);

        // int n=cost.size();
        // vector<int> dp(n+1,-1);
        // int zeroindex=solveMem(cost,0,dp);
        // int oneIndex=solveMem(cost,1,dp);
        // return min(zeroindex,oneIndex);

        // return solveTab(cost);

        return SpaceOpti(cost);
    }
};