class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> free(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int fi=items[i][0];
                    int fj=items[j][0];
                    if(fj%fi==0)free[i]++;
                }
            }
        }
        vector<int> dp(budget+1,0);
        for(int i=0;i<n;i++){
            int p=items[i][1];
            int cpy=1+free[i];
            for(int j=budget;j>=p;j--){
                dp[j]=max(dp[j],dp[j-p]+cpy);
            }
            int val=1;
            for(int j=p;j<=budget;j++){
                dp[j]=max(dp[j],dp[j-p]+val);
            }
        }
        return dp[budget];
    }
};