class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        vector<vector<int>> drn={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,1},{1,-1},{1,0}};
       
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vis[0][0]=true;
        while(!q.empty()){
            auto top= q.front();
            q.pop();
            int len=top.first;
            int x=top.second.first;
            int y=top.second.second;
            if(x==n-1 && y==n-1)return len;
            for(auto d:drn){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && vis[nx][ny]==false){
                    q.push({len+1,{nx,ny}});
                    vis[nx][ny]=true;
                }
            }
        }
        return -1;
    }
};