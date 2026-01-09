class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
           
        }
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto top= *st.begin();
            st.erase(top);
            int d = top.first;
            int node= top.second;
            for(auto nbr:adj[node]){
                int u=nbr.first;
                int w=nbr.second;
                if(d+w<dist[u]){
                    auto it= st.find({dist[u],u});
                    if(it!=st.end())st.erase(it);
                    dist[u]=d+w;
                    st.insert({dist[u],u});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<dist.size();i++){
            if(dist[i]>ans)ans=dist[i];
            if(dist[i]==INT_MAX)return -1;
        }
        return ans;
    }
};