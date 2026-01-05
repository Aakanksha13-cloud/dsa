class Solution {
public:
   void dfs(int src,int parent,vector<int>& times,unordered_map<int,vector<int>>& adj){
      times[src]++;
      for(auto nbr:adj[src]){
        if(times[nbr]==0)dfs(nbr,src,times,adj);
        else if(times[nbr]!=0 && parent!=nbr){
            times[nbr]++;
            continue;
            
        }
      }
   }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //ans=no.of cycles
        if(connections.size()<n-1)return -1;
        unordered_map<int,vector<int>> adj;
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int> times(n,0);
        int disconnected=0;
        int parent=-1;
        for(int i=0;i<n;i++){
            if(times[i]==0){
                dfs(i,parent,times,adj);
                disconnected++;
            }
        }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     if(times[i]>1)ans++;
        // }
        // if(disconnected>ans)return -1;
        // if(disconnected<ans)return disconnected-1;
        // return ans-1;
        return disconnected-1;
    }
};