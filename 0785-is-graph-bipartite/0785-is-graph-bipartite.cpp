class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int u=0;u<n;u++){
            if(color[u]==-1){
                color[u]=0;
                queue<int>q;
                q.push(u);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto adj:graph[node]){
                       if(color[node]==color[adj])return false;
                       if(color[adj]==-1){
                        color[adj]=1-color[node];
                       q.push(adj);
                       }
                    }
                }
            }
            
        }
        return true;
    }
};