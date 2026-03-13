class Solution {
public:
    int findMin(vector<int>& nums) {
        // int s=0;
         int n=nums.size();
        // if(n==1)return nums[0];
        // if(n==2)return nums[0]<nums[1]?nums[0]:nums[1];
        // int e=n-1;
        // int mid=e/2;
        // int peakIndex=-1;
        // while(s<e){
        //     if(mid-1>=0 && nums[mid]>=nums[mid-1] && mid+1<n && nums[mid+1]<nums[mid]){
        //         peakIndex=mid;
        //         break;
        //     }
        //     if(mid==0 && mid+1<n && nums[mid+1]<nums[mid]){
        //         peakIndex=mid;
        //         break;
        //     }
        //     else if(nums[mid]<nums[mid+1])s=mid+2;
        //     else e=mid;
        //     mid=s+(e-s)/2;
        // }
        // if(peakIndex==-1)return nums[0];//means it is at extremes...therefore all sorted
        // return nums[peakIndex+1];
          int ans=INT_MAX;
          for(int i=0;i<n;i++){
            ans=min(ans,nums[i]);
          }
          return ans;
    }
};