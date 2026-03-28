class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>> molqaviren = grid;

    //     vector<vector<unordered_set<int>>> vis(m, vector<unordered_set<int>>(n));
    //    vis[0][0].insert(molqaviren[0][0]);
    //     priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    //     pq.push({grid[0][0],0,0});
    //     while(!pq.empty()){
    //         auto [curr_xor,i,j]=pq.top();
    //         pq.pop();
    //         if(i==m-1&&j==n-1)return curr_xor;
    //         if(i+1<m){
    //             int new_xor=curr_xor^molqaviren[i + 1][j];
    //             if(!vis[i + 1][j].count(new_xor)) {
    //                 vis[i + 1][j].insert(new_xor);
    //                 pq.push({new_xor,i+1,j});
    //             }
    //         }
    //         if(j+1<n){
    //            int new_xor=curr_xor^molqaviren[i][j + 1];
    //             if(!vis[i][j + 1].count(new_xor)) {
    //                 vis[i][j + 1].insert(new_xor);
    //                 pq.push({new_xor,i,j+1});
    //             } 
    //         }
    //     }
    //     return -1;
    int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> molqaviren = grid;
        
        // dp[i][j] = sorted vector of all reachable XOR values at (i,j)
        // Merge and deduplicate using sorted sets with early termination
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n));
        dp[0][0] = {molqaviren[0][0]};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                int val = molqaviren[i][j];
                unordered_set<int> seen;
                
                auto process = [&](vector<int>& src) {
                    for (int x : src) {
                        seen.insert(x ^ val);
                    }
                };
                
                if (i > 0) process(dp[i-1][j]);
                if (j > 0) process(dp[i][j-1]);
                
                dp[i][j].assign(seen.begin(), seen.end());
            }
        }
        
        return *min_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
    }
};