class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //approach: if mid: even-> single ele at left or mid 
        //mid:odd->single ele at right

        int s=0;
        int e=nums.size()-1;
        int mid=e/2;
        while(s<e){
            if(mid%2==1)mid--;
            if(nums[mid]==nums[mid+1])s=mid+2;
        
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return nums[s];
    }
};