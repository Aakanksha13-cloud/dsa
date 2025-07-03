class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row : grid) {
        sort(row.rbegin(), row.rend());
        }
        int ans=0;
        for(int i=0;i<grid[0].size();i++){
            int maxrow = INT_MIN;
           for(int j=0;j<grid.size();j++){
              maxrow=max(maxrow,grid[j][i]);
           }
           ans+=maxrow;
        }
        return ans;
    }
};