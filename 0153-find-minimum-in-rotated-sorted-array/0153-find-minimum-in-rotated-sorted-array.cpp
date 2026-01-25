class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=(e-s)/2;
        while(s<=e){
            if(s==e)return nums[s];
            if(nums[mid]>nums[e])s=mid+1;
            else e=mid;
            mid=s+(e-s)/2;
        }
        return -1;
    }
};