class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //shortest time
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        vector<long long> ways(n,0);
        ways[0]=1;
        const long long MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        set<pair<long long,int>> st;
        st.insert({0,0});
        while(!st.empty()){
            auto top=*st.begin();
            st.erase(top);
            long long d=top.first;
            int node=top.second;
            if(d>dist[node])continue;
            for(auto nbr:adj[node]){
                int u = nbr.first;
                long long w=nbr.second;
                if(d+w<dist[u]){
                    auto it=st.find({dist[u],u});
                    if(it!=st.end())st.erase(it);
                    dist[u]=d+w;
                    st.insert({dist[u],u});
                    ways[u]=ways[node];
                }
                else if(d+w==dist[u]){
                    ways[u]= (ways[u]+ways[node])%MOD;
                }
            }
        }
        int ans = ways[n-1]%MOD;
        return ans;
    }
};