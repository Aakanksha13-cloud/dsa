class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=nums.size()-1;
        while(j>=i){
            
            if(nums[i]==val){
                while(j>i && nums[j]==val)j--;
                if(i<=j)swap(nums[i],nums[j]); j--;
               
            }
           
            else i++;
        }
        return j+1;
    }
};