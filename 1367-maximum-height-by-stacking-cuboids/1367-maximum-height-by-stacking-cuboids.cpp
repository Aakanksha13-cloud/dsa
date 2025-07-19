class Solution {
public:
    bool isSafe(vector<int> c1,vector<int> c2){
        if(c1[0]>=c2[0] && c1[1]>=c2[1] && c1[2]>=c2[2])return true;
        else return false;
    }
    //top-bottom
    int rec(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>>& dp){
        if(curr>=cuboids.size())return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int inc=0;
        int exc=0;
        if(prev==-1 || isSafe(cuboids[curr],cuboids[prev])){
            inc=cuboids[curr][2]+rec(cuboids,curr+1,curr,dp);
        }
        exc=rec(cuboids,curr+1,prev,dp);
        dp[curr][prev+1]= max(inc,exc);
        return dp[curr][prev+1];

    }
    int solveTab(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int inc=0;
                int exc=0;
                 if(prev==-1 || isSafe(cuboids[curr],cuboids[prev])){
                  inc=cuboids[curr][2]+dp[curr+1][curr+1];
                 }
                exc=dp[curr+1][prev+1];
                dp[curr][prev+1]= max(inc,exc);
            }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        // int n=cuboids.size();
        // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        //return rec(cuboids,0,-1,dp);
        return solveTab(cuboids);
    }
};