class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();
        vector<long long> prev(n+1,0);
        for(int i=0;i<n;i++){
            prev[i+1]=prev[i]+nums[i];
        }
        const long long limit=1e15;
        //dp[i][j]-> prev i length, =<j subarray
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-limit));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;//0 subarray->0 sum
        }
        long long ans=-limit;
        for(int j=1;j<=m;j++){
            deque<int> dq;
            for(int i=1;i<=n;i++){
                dp[i][j]=dp[i-1][j];
                int a=i-l;
                if(a>=0 && dp[a][j-1]!=-limit){
                    long long val=dp[a][j-1]-prev[a];
                    while(!dq.empty() && (dp[dq.back()][j-1]-prev[dq.back()])<=val){
                        // int last=dq.back();
                        // long long x=dp[last][j-1]-prev[last];
                        // if(x<=val){
                            dq.pop_back();
                        // }
                        // else break;
                    }
                    dq.push_back(a);
                }
                while(!dq.empty()&&dq.front()<i-r){
                    dq.pop_front();
                }
                if(!dq.empty()){
                    int wow=dq.front();
                    dp[i][j]=max(dp[i][j],prev[i]+(dp[wow][j-1]-prev[wow]));
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};