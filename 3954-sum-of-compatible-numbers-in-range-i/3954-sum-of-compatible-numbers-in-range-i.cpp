class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s=max(1,n-k);
        int e=n+k;
        int x=s;
        int ans=0;
        while(x>= s && x<=e){
            if((n&x)==0)ans+=x;
            x++;
        }
        return ans;
    }
};