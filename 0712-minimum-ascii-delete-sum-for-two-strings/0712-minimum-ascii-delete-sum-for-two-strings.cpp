class Solution {
public:
    int rec(string& s1, string& s2,int i,int j,vector<vector<int>>& dp){
        if (i==s1.length() && j==s2.length())return 0;
        
         if(i>=s1.length() && j<s2.length()){
            int val=0;
            for(int k=j;k<s2.length();k++){
              val+=s2[k];
            }
            dp[i][j]=val;
            return dp[i][j];
        }
        else if(i<s1.length() && j>=s2.length()){
           int val=0;
            for(int k=i;k<s1.length();k++){
              val+=s1[k];
            }
            dp[i][j]=val;
            return dp[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<s1.length() && j<s2.length() && s1[i]==s2[j])dp[i][j]=rec(s1,s2,i+1,j+1,dp);
        else if(i<s1.length() && j<s2.length() && s1[i]!=s2[j]){
            int opt1 = s1[i]+ rec(s1,s2,i+1,j,dp);
            int opt2 = s2[j]+ rec(s1,s2,i,j+1,dp);
            dp[i][j]= min(opt1,opt2);

        }
       return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        //return rec(s1,s2,0,0);
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(s1,s2,0,0,dp);
    }
};