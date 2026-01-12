class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        const int OFFSET = 10001;

        // Build graph
        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + OFFSET;
            //int col = s[1];
            adj[row].push_back(col);
            adj[col].push_back(row);
        }

        int components = 0;

        // BFS for connected components
        for (auto &s : stones) {
            int start = s[0];
            if (visited.count(start)) continue;

            components++;
            queue<int> q;
            q.push(start);
            visited.insert(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {
                    if (!visited.count(nbr)) {
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
        }

        return stones.size() - components;
    }
};