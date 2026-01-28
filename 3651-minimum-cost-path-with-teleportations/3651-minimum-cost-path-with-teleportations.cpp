class Solution {
public:
    // int minCost(vector<vector<int>>& grid, int k) {
    //     vector<vector<int>> drn ={{0,1},{1,0}};
    //     vector<vector<int>> nbr={{0,1},{1,0},{1,1}};
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    //     pq.push({0,{0,0}});
    //     while(!pq.empty()){
    //         int cost=pq.top().first;
    //         int i=pq.top().second.first;
    //         int j=pq.top().second.second;
    //         pq.pop();
    //         grid[i][j]=-1;
    //         if(i==m-1 && j==n-1)return cost;
    //         for(auto nb:nbr){
    //             if(k>0){
    //                 int x=i+nb[0];
    //                 int y=j+nb[1];
    //                 if(x>=0 && x<m && y>=0 && y<n && grid[x][y]<=grid[i][j] && grid[x][y]!=-1){
    //                     pq.push({cost,{x,y}});
    //                     k--;
    //                 }
    //             }
    //         }
    //         for(auto d:drn){
    //             int x=i+d[0];
    //             int y=j+d[1];
    //             if(x>=0 && x<m && y>=0 && y<n && grid[x][y]!=-1){
    //                 pq.push({cost+grid[x][y],{x,y}});
    //             }
    //         }
    //     }
    //     return -1;
    // }

    int minCost(vector<vector<int>>& grid, int k) {

    int m = grid.size(), n = grid[0].size();

    const long long INF = 1e18;

    // dist[i][j][t] = min cost to reach (i,j) after using t teleports
    vector dist(m,
        vector(n, vector<long long>(k+1, INF)));

    using State = tuple<long long,int,int,int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[0][0][0] = 0;
    pq.push({0,0,0,0});

    // All cells sorted by grid value
    vector<tuple<int,int,int>> cells;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cells.push_back({grid[i][j], i, j});

    sort(cells.begin(), cells.end());

    // For each teleport layer t, pointer in sorted cells
    vector<int> ptr(k+1, 0);

    while(!pq.empty()) {

        auto [cost, i, j, t] = pq.top();
        pq.pop();

        if(cost > dist[i][j][t]) continue;

        if(i == m-1 && j == n-1)
            return cost;

        // ---- Normal Moves ----
        if(i+1 < m) {
            long long nc = cost + grid[i+1][j];
            if(nc < dist[i+1][j][t]) {
                dist[i+1][j][t] = nc;
                pq.push({nc, i+1, j, t});
            }
        }

        if(j+1 < n) {
            long long nc = cost + grid[i][j+1];
            if(nc < dist[i][j+1][t]) {
                dist[i][j+1][t] = nc;
                pq.push({nc, i, j+1, t});
            }
        }

        // ---- Teleportation ----
        if(t < k) {

            while(ptr[t] < cells.size() &&
                  get<0>(cells[ptr[t]]) <= grid[i][j]) {

                auto [val, x, y] = cells[ptr[t]];
                ptr[t]++;

                if(cost < dist[x][y][t+1]) {
                    dist[x][y][t+1] = cost;
                    pq.push({cost, x, y, t+1});
                }
            }
        }
    }

    return -1;
}


};