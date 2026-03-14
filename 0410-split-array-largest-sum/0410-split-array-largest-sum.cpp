class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxSum){
        int subarr=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxSum)return false;
            if(sum+nums[i]>maxSum){
                subarr++;
                sum=nums[i];
                if(subarr>k)return false;
            }
            else sum+=nums[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums,k,mid)){
               ans=mid;
               e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};