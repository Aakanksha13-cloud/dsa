class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
       int m = grid.size();
       int n= grid[0].size();
       int ans=0;
       queue<pair<int,int>> q;
       vector<vector<int>> drn ={{-1,0},{1,0},{0,1},{0,-1}};

       for(int i=0;i<m;i++){
        if(grid[i][0]==1){
            q.push({i,0});
            grid[i][0]=-1;
        }
        if(grid[i][n-1]==1){
            q.push({i,n-1});
            grid[i][n-1]=-1;
        }
       }
       for(int j=0;j<n;j++){
        if(grid[0][j]==1){
            q.push({0,j});
            grid[0][j]=-1;
        }
        if(grid[m-1][j]==1){
            q.push({m-1,j});
            grid[m-1][j]=-1;
        }
       }
       
       while(!q.empty()){
            auto frontNode= q.front();
            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;
            for(auto d:drn){
                int nr= r+d[0];
                int nc=c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=-1;    
            }
        }
       }

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                ans++;
            }
            else if(grid[i][j]==-1)grid[i][j]=1;
        }
       }
       return ans; 
    }
};