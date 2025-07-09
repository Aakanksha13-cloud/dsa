class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col= matrix[0].size();
        int i=0;
        while(i<row){
            if(matrix[i][0]<=target && matrix[i][col-1]>=target){
               int s=0;
               int e=col-1;
               int mid = (e-s)/2;
               while(s<=e){
                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]<target)s=mid+1;
                else e = mid-1;
                mid= s+(e-s)/2;
               }
            }
            i++;
        }
        return false;
    }
};