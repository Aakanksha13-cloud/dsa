class Solution {
public:
    int kthGrammar(int n, int k) {
        //tle
        // if(n==1 && k==1)return 0;
        // if(n==1 && k>1)return -1;
        // vector<string> row(n+1);
        // row[1]='0';
        // int prev=1;
        // int curr=2;
        // while(curr<=n){
        //     for(char c: row[prev]){
        //         if(c=='0')row[curr]+="01";
        //         else if(c=='1')row[curr]+="10";
        //     }
        //     prev=curr;
        //     curr++;
        // }
        // string ans= row[n];
        // int result = ans[k-1]-'0';
        // return result;

        if(n == 1) return 0;

        int mid = pow(2, n - 1) / 2;

        if(k <= mid)
            return kthGrammar(n - 1, k);
        else
            return !kthGrammar(n - 1, k - mid);
    }
};