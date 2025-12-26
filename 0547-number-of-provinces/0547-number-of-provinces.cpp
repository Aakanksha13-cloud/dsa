class Solution {
public:
   void bfs(int src,unordered_map<int,bool>& vis,unordered_map<int,vector<int>>& adj){
     queue<int> q;
     q.push(src);
     vis[src]=true;
     while(!q.empty()){
        int frontNode= q.front();
        q.pop();
        for(auto nbr: adj[frontNode]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr]=true;
            }
        }
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        unordered_map<int,bool> vis;
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};