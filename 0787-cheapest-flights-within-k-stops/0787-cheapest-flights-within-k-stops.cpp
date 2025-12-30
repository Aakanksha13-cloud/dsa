class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        //min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});
        vector<int> vis(n+1,INT_MAX);
        vis[src]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int cost= curr[0];
            int city= curr[1];
            int stop=curr[2];
            if(city==dst)return cost;
            if(vis[city]!=INT_MAX && vis[city]<stop)continue;
            vis[city]=min(vis[city],stop);
            if(stop>k)continue;
            for(auto nbr:adj[city]){
                pq.push({nbr.second+cost,nbr.first,stop+1});
            }
        }
        return -1;
    }
};