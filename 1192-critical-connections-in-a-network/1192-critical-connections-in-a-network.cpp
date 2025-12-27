class Solution {
public:
    void Tarjan(int src,int parent, vector<int> &tin,vector<int>& low,unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& vis, int timer,vector<vector<int>>& ans){
        
        timer++;
        vis[src]=true;
        tin[src]=timer;
        low[src]=timer;
        for(auto nbr:adj[src]){
            if(nbr==parent)continue;
            else if(!vis[nbr]){
                Tarjan(nbr,src,tin,low,adj,vis,timer,ans);
                low[src]=min(low[src],low[nbr]);
                if(low[nbr]>tin[src]){
                   vector<int> temp={src,nbr};
                   ans.push_back(temp); 
                }
            }
            else low[src]=min(low[src],low[nbr]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n);
        vector<int> low(n);
        int timer=0;
        unordered_map<int,bool> vis;
        int parent=-1;
        int src=0;
        Tarjan(src,parent,tin,low,adj,vis,timer,ans);
        return ans;
    }
};