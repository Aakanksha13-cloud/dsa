class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n)return;
        grid[i][j]='0'; //visited
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> drn={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+drn[i][0];
                int ny=y+drn[i][1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    grid[nx][ny]='0';
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};