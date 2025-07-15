class Solution {
public:
    // vector<vector<int>> ans;
    // vector<int> rec(int n,int index){
    //     vector<int> nums(n+1,1);
    //     if(nums.size()>2){
    //         for(int i=1;i<nums.size()-1;i++){
    //             nums[i] = rec(n-1,i-1)+rec(n-1,i);
    //         }
    //     }
    //     ans.push_back(nums);
    // }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
       for(int i=0;i<numRows;i++){
          vector<int> nums(i+1,1);
          if(nums.size()>2){
            for(int j=1;j<nums.size()-1;j++){
                nums[j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        ans.push_back(nums);
       }
       return ans;
    }
};