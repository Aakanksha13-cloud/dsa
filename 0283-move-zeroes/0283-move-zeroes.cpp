class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count++;
        }
        int i=0;
        int j=0;
        while(i<nums.size() && j<nums.size()-count){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        for(int k=nums.size()-count;k<nums.size();k++){
            nums[k]=0;
        }
    }
};