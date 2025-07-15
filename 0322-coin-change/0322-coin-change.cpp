class Solution {
public:
    int minCoinMem(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1)return dp[amount];
        int mincoinsUsed = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];
            if(coin<=amount){
                int restCoins = minCoinMem(coins, amount-coin,dp);
                if(restCoins!= INT_MAX){
                  int coinUsed = 1+ restCoins;
                  mincoinsUsed = min(mincoinsUsed, coinUsed);
                }
            }
        }
        dp[amount]=mincoinsUsed;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = minCoinMem(coins, amount,dp);
        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};