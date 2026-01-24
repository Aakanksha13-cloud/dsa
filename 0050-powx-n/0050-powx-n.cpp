class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        double ans=1;
        long long power=n;
        if(power<0){
            x=1/x;
            power=-power;
        }
        
        //log2n
        while(power>0){
            if(power%2==1)ans*=x;
            x*=x;
            power/=2;
        }
        
        return ans;
    }
};