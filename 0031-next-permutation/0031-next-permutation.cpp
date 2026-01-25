class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //desc order sort
        if(is_sorted(nums.begin(),nums.end(),greater<int>())){
            sort(nums.begin(),nums.end());
            return;
        }
        int n=nums.size();
        int i=n-2;
        int index=-1;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
            i--;
        }
        int justGreater=index+1;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>nums[index] && nums[i]<=nums[justGreater]){
                justGreater=i;
            }
        }
        swap(nums[justGreater],nums[index]);
        reverse(nums.begin()+index+1,nums.end());
    }
};