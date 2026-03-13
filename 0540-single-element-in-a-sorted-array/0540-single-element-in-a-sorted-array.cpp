class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //approach: if mid: even-> single ele at left or mid 
        //mid:odd->single ele at right

        // int s=0;
        // int e=nums.size()-1;
        // int mid=e/2;
        // while(s<e){
        //     if(mid%2==1)mid--;
        //     if(nums[mid]==nums[mid+1])s=mid+2;
        
        //     else{
        //         e=mid;
        //     }
        //     mid=s+(e-s)/2;
        // }
        // return nums[s];

        // int s=0;
        // int n=arr.size();
        // int e=arr.size()-1;
        // int mid=e/2;
        // while(s<=e){
        //     if(s==e)return mid;
        //     if(mid-1>=0 && arr[mid]!=arr[mid-1] && mid+1<n && arr[mid]!=arr[mid+1])arr[mid];
        //     if(mid-1>=0 && arr[mid]==arr[mid-1]){
        //         int startindex=mid-1;
        //         if(startindex%2!=0)e=mid-1;
        //         else s=mid+1;
        //     }
        //     else if(mid+1<n && arr[mid]==arr[mid+1]){
        //         int startindex=mid;
        //         if(startindex%2!=0)e=mid-1;
        //         else s=mid+1;
        //     }
        //     mid=s+(e-s)/2;
        // }

        int s=0;
        int n=nums.size();
        int e=n-1;
        int mid=e/2;
        while(s<e){
            if(mid%2==1)mid--;
            if(nums[mid]==nums[mid+1])s=mid+2;
            else e=mid;
            mid=s+(e-s)/2;
        }
        return nums[s];
        return -1;
    }
};