class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]}); //v,w
            adj[e[1]].push_back({e[0],2*e[2]});
        }
        // vector<vector<pair<int,long long>>>revadj(n);
        // for(auto e:edges){
        //     revadj[e[1]].push_back({e[0],2*e[2]}); //v,w
        // }
       
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n-1)return d;
            
            
            if(dist[node]!=d)continue; //means it's not updated with latest dist...hence traversing again prev one
            for(auto& a:adj[node]){
                int v=a.first;
                long long w=a.second;
                if(w+d<dist[v]){
                    pq.push({w+d,v});
                    dist[v]=w+d;
                }
            }

            // for(auto r:revadj[node]){
            //     int v=r.first;
            //     long long w=r.second;
            //     if(w+d<=dist[v]){
            //         pq.push({w+d,v});
            //         dist[v]=w+d;
            //     }
            // }
        }

        return -1;
    }
};