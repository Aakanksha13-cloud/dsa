class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outdegree(n, 0);

        // Build reverse graph and outdegree array
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
            }
        }

        queue<int> q;
        // Push terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int parent : reverseGraph[node]) {
                outdegree[parent]--;
                if (outdegree[parent] == 0)
                    q.push(parent);
            }
        }

        // Collect safe nodes
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                result.push_back(i);
        }

        return result; // already sorted
    }
};
    
