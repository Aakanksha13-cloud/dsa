class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //shortest path 
        vector<vector<int>> drn={{-1,0},{1,0},{0,1},{0,-1}};
        int n=grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        grid[0][0]=-1;
        while(!pq.empty()){
            int time= pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==n-1)return time;
            if(time>dist[x][y])continue;
            for(auto d:drn){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=-1){
                    int newTime = max(time,grid[nx][ny]);
                    if(newTime<dist[nx][ny]){
                        dist[nx][ny]=newTime;
                        pq.push({newTime,{nx,ny}});
                        grid[nx][ny]=-1;
                    }
                }
            }
        }
        return -1;
    }
};