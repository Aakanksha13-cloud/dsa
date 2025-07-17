class Solution {
public:
    int rec(string s, string t,int i,int j,vector<vector<int>> &dp){
        if(j==t.size())return 1;
        if(i==s.length())return 0;

       if(dp[i][j]!=-1)return dp[i][j];
        int inc=0;
        int exc=0;
        if(i<s.length() && j<t.length() && s[i]==t[j]){
            inc=rec(s,t,i+1,j+1,dp);         
        }
        exc=rec(s,t,i+1,j,dp);
        dp[i][j]= inc+exc;
        return dp[i][j];
       
    }
    int solveTab(string s, string t){
        int n=s.length();
        int m=t.length();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
        }
        for(int i=0;i<m;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                unsigned long long inc=0;
               unsigned long long exc=0;
               if(s[i]==t[j])inc=dp[i+1][j+1];       
               exc=dp[i+1][j];
               dp[i][j]= inc+exc;
            }
        }
        return (int)dp[0][0];
    }
    int numDistinct(string s, string t) {
        //return rec(s,t,0,0);
        // int n=s.length();
        // int m=t.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return rec(s,t,0,0,dp);

        return solveTab(s,t);
    }
};