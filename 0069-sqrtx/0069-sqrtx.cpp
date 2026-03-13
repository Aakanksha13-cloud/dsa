class Solution {
public:
    int mySqrt(int x) {
        long long s=0;
        long long e=x;
        long long mid=e/2;
        long long ans;
        while(s<=e){
            long long pro=mid*mid;
            if(pro==x)return mid;
            else if(pro<x){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};