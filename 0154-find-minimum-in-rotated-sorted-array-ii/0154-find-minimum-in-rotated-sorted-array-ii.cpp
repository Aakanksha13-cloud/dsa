class Solution {
public:
    int findMin(vector<int>& nums) {
         int s=0;
         int n=nums.size();
        if(n==1)return nums[0];
        int e=n-1;
        int mid=e/2;
        
        while(s<e){
            if(mid-1>=0 && nums[mid]<nums[mid-1])return nums[mid];
            if(mid+1<n && nums[mid+1]<nums[mid])return nums[mid+1];
            else if(nums[mid]>nums[e])s=mid+1;
            else if(nums[mid]<nums[e])e=mid;
            else e--;
            mid=s+(e-s)/2;
        }
        
        return nums[mid];

        //   int ans=INT_MAX;
        //   for(int i=0;i<n;i++){
        //     ans=min(ans,nums[i]);
        //   }
        //   return ans;
    }
};