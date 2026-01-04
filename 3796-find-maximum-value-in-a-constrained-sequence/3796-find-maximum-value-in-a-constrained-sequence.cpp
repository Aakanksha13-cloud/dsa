class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> a(n,LLONG_MAX);
        a[0]=0;

        for(auto r:restrictions){
            a[r[0]]=min(a[r[0]],(long long)r[1]);
        }

        for(int i=1;i<n;i++){
            a[i]=min(a[i],a[i-1]+diff[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            a[i]=min(a[i],a[i+1]+diff[i]);
        }

        long long ans=0;
        for(int i=0;i<a.size();i++){
            ans=max(ans,a[i]);
        }
        return ans;
    }
};