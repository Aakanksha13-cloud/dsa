class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> drn={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> obsused(m,vector<int>(n,INT_MAX));
        queue<vector<int>> q;
        q.push({0,0,0,0});
        obsused[0][0]=0;
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return -1;
        if(m==1 && n==1)return 0;
        while(!q.empty()){
            auto front=q.front();
            int x=front[0];
            int y=front[1];
            int used=front[2];
            int steps=front[3];
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+drn[i][0];
                int ny=y+drn[i][1];
                if(nx<0 || ny<0 || nx>=m || ny>=n)continue;
                int nowused= used+grid[nx][ny];
                if(nowused>k)continue;
                if(nx==m-1 && ny==n-1)return steps+1;
                if(obsused[nx][ny]<=nowused)continue; //maintain min obs used path+prevent revisiting
                obsused[nx][ny]=nowused;
                q.push({nx,ny,nowused,steps+1});
            }
        }
        return -1;
    }
};