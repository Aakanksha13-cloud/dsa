class Solution {
public:
    int dfs(int x,int y,vector<vector<int>>& grid,int id,int n, vector<vector<int>>& drn){
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y]!=1)return 0;

        grid[x][y]=id;
        int size=1;
        for(auto d:drn){
            int nx=x+d[0];
            int ny=y+d[1];
            size += dfs(nx,ny,grid,id,n,drn);
        }

        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n =grid.size();
        unordered_map<int,int> Islandsize;
        int id=2;
        int ans=0;
        vector<vector<int>> drn={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=dfs(i,j,grid,id,n,drn);
                    Islandsize[id]=size;
                    id++;
                    ans=max(ans,size);
                }
            }
        }
        //turn wise 0
       
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 ){
                    unordered_set<int> vis;//taki hum ek id ko ek hi baar consider kare
                    int currsize=1;
                    for(auto d:drn){
                        int x = i+d[0];
                        int y= j+d[1];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]>1){
                            int IslandId= grid[x][y];
                            if(!vis.count(IslandId)){
                                currsize += Islandsize[IslandId];
                                vis.insert(IslandId);
                            }
                        }
                    }
                    ans=max(ans,currsize);
                }
            }
        }
        return ans;
    }
};