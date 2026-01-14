class Solution {
public:
    // int n;
    // unordered_map<int, int> islandSize;
    // int dx[4] = {1, -1, 0, 0};
    // int dy[4] = {0, 0, 1, -1};

    // int dfs(int x, int y, vector<vector<int>>& grid, int id) {
    //     if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1)
    //         return 0;

    //     grid[x][y] = id;
    //     int size = 1;

    //     for (int d = 0; d < 4; d++)
    //         size += dfs(x + dx[d], y + dy[d], grid, id);

    //     return size;
    // }
    // int largestIsland(vector<vector<int>>& grid) {
    //     // hit n trial
    //     // pehle disconnected compo me se max size
    //     // then 0 aate hi change to 1 then same then backtrack 1 to 0
    //      n = grid.size();
    //     int id = 2;   // start from 2 (0 and 1 already used)
    //     int ans = 0;

    //     // 1️⃣ Label islands and store sizes
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 1) {
    //                 int size = dfs(i, j, grid, id);
    //                 islandSize[id] = size;
    //                 ans = max(ans, size);
    //                 id++;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 0) {
    //                 unordered_set<int> seen;
    //                 int currSize = 1;  // flipped cell

    //                 for (int d = 0; d < 4; d++) {
    //                     int ni = i + dx[d];
    //                     int nj = j + dy[d];

    //                     if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
    //                         grid[ni][nj] > 1) {

    //                         int islandId = grid[ni][nj];
    //                         if (!seen.count(islandId)) {
    //                             currSize += islandSize[islandId];
    //                             seen.insert(islandId);
    //                         }
    //                     }
    //                 }
    //                 ans = max(ans, currSize);
    //             }
    //         }
    //     }

    //     return ans;
    // }
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
                    unordered_set<int> vis;
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