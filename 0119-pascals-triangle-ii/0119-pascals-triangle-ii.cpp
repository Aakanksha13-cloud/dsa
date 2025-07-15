class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        for(int i=0;i<=rowIndex;i++){
            vector<int> nums(i+1,1);
            if(nums.size()>2){
                for(int j=1;j<nums.size()-1;j++){
                    nums[j]=pascal[i-1][j-1]+pascal[i-1][j];
                }
            }
            pascal.push_back(nums);
        }
        return pascal[rowIndex];
    }
};