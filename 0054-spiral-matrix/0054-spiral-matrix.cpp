class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        if(m==0)return ans;
        int row=0;
        int bottom=m-1;
        int col = 0;
        int right = n-1;
        while(row<=bottom && col<=right){
            for(int i=col; i<=right;i++){
                ans.push_back(matrix[row][i]);
            }
            row++;

            for(int j=row; j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;

            if(row<=bottom){
                for(int k=right;k>=col;k--){
                    ans.push_back(matrix[bottom][k]);
                }
                bottom--;
            }
            if(col<=right){
                for(int r=bottom;r>=row;r--){
                    ans.push_back(matrix[r][col]);
                }
                col++;
            }
        }
        return ans;
    }
};