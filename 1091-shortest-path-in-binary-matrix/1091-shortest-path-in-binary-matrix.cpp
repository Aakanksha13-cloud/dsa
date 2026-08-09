class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<int>> drn={{-1,0},{-1,-1},{-1,1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        pq.push({1,{0,0}});
        grid[0][0]=1;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int dist=t.first;
            int x=t.second.first;
            int y=t.second.second;
            if(x==n-1 && y==n-1)return dist;
            for(int i=0;i<8;i++){
                int nx=x+drn[i][0];
                int ny=y+drn[i][1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    pq.push({dist+1,{nx,ny}});
                    grid[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};