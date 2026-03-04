class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=1;
        //int mid=e/2;
        int ans=0;
        while(s<=e && e<nums.size()){
           if(s>0 && nums[s]==nums[s-1]){
            s++;
            continue;
           }
           if((e<nums.size()-1 && nums[e]==nums[e+1]) || s==e){
            e++;
            continue;
           }
           if(abs(nums[e]-nums[s])==k){
            ans++;
            s++;
            e++;
           }
           else if(abs(nums[e]-nums[s])>k)s++;
           else e++;
        }
        return ans;
    }
};