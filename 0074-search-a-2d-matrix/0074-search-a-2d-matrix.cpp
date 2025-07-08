class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col= matrix[0].size();
        int i=0;
        while(i<row){
            if(matrix[i][0]<=target && matrix[i][col-1]>=target){
                for(int j=0;j<col;j++){
                    if(matrix[i][j]==target)return true;
                }
            }
            i++;
        }
        return false;
    }
};