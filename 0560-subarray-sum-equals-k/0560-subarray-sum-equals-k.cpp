class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0;
        
        for(int i=0;i<n;i++){
           sum+=nums[i];
           int diff=sum-k;
           if(m.find(diff)!=m.end()){
            ans+=m[diff];
           }
           m[sum]++;
        }
        return ans;
    }
};