class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minutes=0;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        vector<vector<int>> drn={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int s=q.size();
            minutes++;
            for(int i=0;i<s;i++){
                auto t=q.front();
                int r=t.first;
                int c=t.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nr=r+drn[j][0];
                    int nc=c+drn[j][1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }
        if(fresh>0)return -1;
        return minutes;
    }
};