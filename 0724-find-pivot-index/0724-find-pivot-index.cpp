class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum =0;
        int i=0;
        int rightsum =0;
        for(int j=1;j<nums.size();j++){
            rightsum+=nums[j];
        }
        while(i<nums.size()){
            if(leftsum==rightsum)return i;
            leftsum+=nums[i];
            if(i==nums.size()-1)rightsum=0;
            else rightsum-=nums[i+1];
            i=i+1;
        }
        return -1;
    }
};