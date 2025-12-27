class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
      int r=heights.size();
      int c=heights[0].size();

      vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
      pq.push({0,{0,0}});
      dist[0][0]=0;
      vector<vector<int>> drn = {{-1,0},{1,0},{0,1},{0,-1}};

      //dijkstra

      while(!pq.empty()){
        int currAbsDiff= pq.top().first;
        int x= pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        if(x == r-1 && y == c-1)return dist[x][y];
        else{
            for(auto d:drn){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && ny>=0 && nx<r && ny<c){
                    int newAbsDiff = abs(heights[x][y]-heights[nx][ny]);
                    int newMaxDiff = max(currAbsDiff,newAbsDiff);
                    if(newMaxDiff<dist[nx][ny]){
                        dist[nx][ny]=newMaxDiff;
                        pq.push({newMaxDiff,{nx,ny}});
                    }
                }
            }
        }
      }
      return 0;
    }
};