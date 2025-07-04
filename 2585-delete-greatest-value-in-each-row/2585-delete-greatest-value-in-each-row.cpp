class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        // for (auto &row : grid) {
        // sort(row.rbegin(), row.rend());
        // }
        // int ans=0;
        // for(int i=0;i<grid[0].size();i++){
        //     int maxrow = INT_MIN;
        //    for(int j=0;j<grid.size();j++){
        //       maxrow=max(maxrow,grid[j][i]);
        //    }
        //    ans+=maxrow;
        // }
        // return ans;
        int n = grid.size();
        int m= grid[0].size();
        vector<priority_queue<int>> heap(n);
        for(int i=0;i<n;i++){
            for(int val : grid[i]){
                heap[i].push(val);
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){
            int maxele= INT_MIN;
            for(int i=0;i<n;i++){
                int val = heap[i].top();
                heap[i].pop();
                maxele=max(maxele,val);
            }
            ans+=maxele;
        }
        return ans;
    }
};