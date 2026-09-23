class Solution {
public:
    // void buySell(vector<int>& prices, int i, int& minPrice, int& maxProfit){
    //     if(i==prices.size())return;
    //     if(prices[i]<minPrice) minPrice = prices[i];
    //     int todaysProfit = prices[i]-minPrice;
    //     if(todaysProfit>maxProfit) maxProfit= todaysProfit;
    //     buySell(prices,i+1,minPrice, maxProfit);
    // }
    void help(vector<int>& prices,int i,int &buy,int &ans){
        if(i>=prices.size())return;
        int curr=prices[i];
        if(curr<buy)buy=curr;
        int currpro=curr-buy;
        if(currpro>ans)ans=currpro;
        help(prices,i+1,buy,ans);
    }
    int maxProfit(vector<int>& prices) {
    //    int minPrice = INT_MAX;
    //    int maxProfit = INT_MIN;
    //    buySell(prices,0,minPrice, maxProfit);
    //    return maxProfit;
    int buy=INT_MAX;
    
    int ans=INT_MIN;
    help(prices,0,buy,ans);
    return ans;
    };
};