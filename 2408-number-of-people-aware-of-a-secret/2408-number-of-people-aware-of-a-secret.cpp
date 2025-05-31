class Solution {
public:
    const int mod=1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int curr=0;
        int ans=1;
        queue<pair<int,int>>delayq,forgetq;
        delayq.push({1,1});
        forgetq.push({1,1});
        for(int i=1;i<=n;i++){
            if(!forgetq.empty() && forgetq.front().first +forget==i){
                auto front = forgetq.front();
                forgetq.pop();
                auto no = front.second;
                ans= (ans-no + mod)%mod;
                curr=(curr-no+mod)%mod;
            }
            if(!delayq.empty()&&delayq.front().first+delay<=i){
                auto front = delayq.front();
                delayq.pop();
                curr =(curr+front.second)%mod;
            }
            if(curr>0){
                ans=(ans+curr)%mod;
                delayq.push({i,curr});
                forgetq.push({i,curr});
            }
        }
        return ans;
    }
};