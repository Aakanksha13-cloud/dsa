class Solution {
public:
    int findMinFibonacciNumbers(int k) {
       vector<int> num ={1,1}; 
       while(num.back()<k)
       {
        int n=num.size();
        num.push_back(num[n-1]+num[n-2]);
       }
       int n=num.size();
       int ans=0;
       for(int i=n-1;i>=0 && k > 0;i--){
          if(num[i]<=k){
           k -= num[i];
            ans++;
          }
       }
       return ans;
    }
};