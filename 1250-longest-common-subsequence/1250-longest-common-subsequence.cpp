class Solution {
public:
    int solveRec(string text1, string text2,int i,int j, vector<vector<int>> dp){
        if(i>=text1.length() || j>=text2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j])ans=1+solveRec(text1,text2,i+1,j+1,dp);
        else ans = max(solveRec(text1,text2,i,j+1,dp),solveRec(text1,text2,i+1,j,dp));
        return dp[i][j]=ans;
    }

    int solveTab(string text1, string text2){
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        dp[n][m]=0;
        for(int i=0;i<n;i++){
            dp[i][m]=0;
        }
        for(int i=0;i<m;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
               int ans=0;
              if(text1[i]==text2[j])ans=1+dp[i+1][j+1];
              else ans = max(dp[i][j+1],dp[i+1][j]);
              dp[i][j]=ans; 
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //return solveRec(text1,text2,0,0);
        // int n=text1.length();
        // int m=text2.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return solveRec(text1,text2,0,0,dp);

        return solveTab(text1,text2);
    }
};