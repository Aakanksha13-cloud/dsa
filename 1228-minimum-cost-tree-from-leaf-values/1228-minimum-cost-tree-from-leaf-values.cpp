class Solution {
public:
    int rec(vector<int>& arr,map<pair<int,int>,int> &maxi,int s,int e,vector<vector<int>>& dp){
        if(s>=e)return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            int leftmax= maxi[{s,i}];
            int rightmax=maxi[{i+1,e}];
            int leaf= leftmax*rightmax;
            ans=min(ans,leaf+ rec(arr,maxi,s,i,dp) + rec(arr,maxi,i+1,e,dp));
        }
        dp[s][e]=ans;
        return dp[s][e];
    }
    int tab(vector<int>& arr,map<pair<int,int>,int> &maxi){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int s=n-1;s>=0;s--){
            for(int e=0;e<=n-1;e++){
                if(s>=e)continue;
                int ans=INT_MAX;
             for(int i=s;i<e;i++){
            int leftmax= maxi[{s,i}];
            int rightmax=maxi[{i+1,e}];
            int leaf= leftmax*rightmax;
            ans=min(ans,leaf+ dp[s][i] + dp[i+1][e]);
        }
        dp[s][e]=ans;
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> maxi;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)maxi[{i,j}]=arr[i];
                else maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
            }
        }
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return rec(arr,maxi,0,n-1,dp);
        return tab(arr,maxi);
    }
};