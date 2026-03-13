class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s=0;
        long long e=num;
        long long mid=e/2;
        while(s<=e){
            long long pro=mid*mid;
            if(pro==num)return true;
            else if(pro<num)s=mid+1;
            else e=mid-1;
            mid=s+(e-s)/2;
        }
        return false;
    }
};