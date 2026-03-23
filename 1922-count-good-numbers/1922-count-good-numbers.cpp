class Solution {
public:
    long long power(long long base, long long exp) {
    long long result = 1;
    long long mod = 1e9 + 7;

    while (exp > 0) {
        if (exp % 2 == 1) { // if odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // square base
        exp /= 2; // divide exponent
    }

    return result;
}
    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        long long odd=0;
        long long even=0;
        if(n%2==0){
            odd=n/2;
            even=n/2;
        }
        else{
            odd=(n-1)/2;
            even=1+(n-1)/2;
        }
        //5 options for even 4 for odd
        long long ans=0;
        long long oddans=power(4,odd);//Ologn
        long long evenans =power(5,even);
        ans=(oddans*evenans)%mod;
        return ans;
    }
};