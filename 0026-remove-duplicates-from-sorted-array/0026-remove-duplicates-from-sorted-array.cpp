class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if (nums.empty()) return 0;
        // int unique=0;
        // int dup = 1;
        // while( dup<nums.size()){
        //     if(nums[unique]==nums[dup]) dup++;
        //    else if(dup<nums.size() && nums[unique]<nums[dup]){
        //         swap(nums[unique+1],nums[dup]);
        //         unique++;
        //         dup++;
        //     }
          
        // }
       
        // return unique+1;
        int n =nums.size();
        int i=0;
        int j=1;
        while(j<n){
            if(nums[i]==nums[j])j++;
            else if(j<n && nums[i]<nums[j]){
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
        }
        return i+1;
    }
};