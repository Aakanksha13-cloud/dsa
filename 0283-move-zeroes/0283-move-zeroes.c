void moveZeroes(int* nums, int numsSize) {
    int count=0;
        for(int i=0;i<numsSize;i++){
            if(nums[i]==0)count++;
        }
        int i=0;
        int j=0;
        while(i<numsSize && j<numsSize-count){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        for(int k=j;k<numsSize;k++){
            nums[k]=0;
        }
}