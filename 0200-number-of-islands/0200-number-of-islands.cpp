class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
       if(i<0 || i>=grid.size()|| j<0 || j>= grid[0].size())return; 
       
       queue<pair<int,int>> q;
       q.push({i,j});
       grid[i][j]='0';
       while(!q.empty()){
        auto frontNode= q.front();
        i=frontNode.first;
        j=frontNode.second;
        q.pop();
        int up = i-1;
        if(up>= 0 && up< grid.size() && grid[up][j]=='1'){
            q.push({up,j});
            grid[up][j]= '0';
        }
        int down = i+1;
        if(down>= 0 && down< grid.size() && grid[down][j]=='1'){
            q.push({down,j});
            grid[down][j]='0';
        }
        int left = j-1;
        if(left>=0 && left<grid[0].size() && grid[i][left]=='1'){
            q.push({i,left});
            grid[i][left] ='0';
        }
        int right = j+1;
        if(right>=0 && right<grid[0].size() && grid[i][right]=='1'){
            q.push({i,right});
            grid[i][right]='0';
        }
       }
       return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans= 0;
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