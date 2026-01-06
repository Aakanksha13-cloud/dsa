class Solution {
public:
    int dijkstra(int src, int n, unordered_map<int,vector<pair<int,int>>>& adj, int distanceThreshold){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        dist[src]=0;
        st.insert({0,src});
        int reachableCities=0;

        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin());
            int d = top.first;
            int node= top.second;

            if(node!=src && d<=distanceThreshold){
                reachableCities++;
            }

            for(auto nbr:adj[node]){
                int currDist= d+ nbr.second;
                if(currDist<dist[nbr.first]){
                    auto it = st.find({dist[nbr.first],nbr.first});
                    if(it!=st.end()){
                        st.erase(it);
                    }
                    dist[nbr.first]=currDist;
                    st.insert({currDist,nbr.first});
                }
            }
        }
        return reachableCities;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        int minreach=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++){
            int reachable = dijkstra(i,n,adj,distanceThreshold);
            if(reachable<=minreach){
                minreach=reachable;
                city=i;
            }
        }
        return city;
    }
};