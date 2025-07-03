class Solution {
public:
    int largestInteger(int num) {
        //if(num/10==0)return num;
        vector<int> nums;
        while(num!=0){
            int digit = num%10;
            nums.push_back(digit);
            num=num/10;
        }
        reverse(nums.begin(),nums.end());
        if(nums.size()==1) return nums[0];
        for(int i =0; i<nums.size()-1;i++){
           for(int j = nums.size()-1; j>i;j--){
            if(nums[i]%2==0){
                if(nums[j]%2==0 && nums[j]>nums[i])swap(nums[i],nums[j]);
                
            }
            else {
                if(nums[j]%2!=0 && nums[j]>nums[i])swap(nums[i],nums[j]);
                
            }
           }
        }
        int ans=0;
        for(int i=0; i<nums.size();i++){
           ans=ans*10 + nums[i];
        }
        return ans;
    }
};