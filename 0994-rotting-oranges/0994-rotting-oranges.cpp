class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int drn[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        int minutes =0;
        int fresh =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh>0){
                       int simultaneousMin = q.size();
                       minutes++;
                       for(int i=0;i<simultaneousMin;i++){
                          auto frontNode= q.front();
                          q.pop();
                          int r= frontNode.first;
                          int c= frontNode.second;
                          for(auto d:drn){
                          int nr = r+ d[0];
                          int nc = c+d[1];
                          if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                            fresh--;
                          }
                       }
                       }
                       
                    }
        if(fresh>0) return -1;
        return minutes;
    }
};