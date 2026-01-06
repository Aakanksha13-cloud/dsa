class Solution {
public:
   //method 1

//    void dfs(int src,vector<int>& times,unordered_map<int,vector<int>>& adj){
//       times[src]++;
//       for(auto nbr:adj[src]){
//         if(times[nbr]==0)dfs(nbr,times,adj);
//         else if(times[nbr]!=0){
//             times[nbr]++;
//             continue;
            
//         }
//       }
//    }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         //ans=no.of cycles
//         if(connections.size()<n-1)return -1;
//         unordered_map<int,vector<int>> adj;
//         for(auto c:connections){
//             adj[c[0]].push_back(c[1]);
//             adj[c[1]].push_back(c[0]);
//         }
//         int disconnected=0;
//         vector<int> times(n,0);
//         for(int i=0;i<n;i++){
//             if(times[i]==0){
//                 dfs(i,times,adj);
//                 disconnected++;
//             }
//         }
//         return disconnected-1;
//     }

//method 2: by kruskal
    int findParent(int node, vector<int>& parent){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node],parent); //path compression
    }

    void unionSet(int u,int v, vector<int>& parent, vector<int>& rank){
        u = findParent(u,parent);
        v= findParent(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections){
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        int extraedge=0;
        for(auto c:connections){
            int u=c[0];
            int v=c[1];

            u=findParent(u,parent);
            v=findParent(v,parent);

            if(u!=v){
                unionSet(u,v,parent,rank);
            }
            else extraedge++;
        }

        int nocc=0; //no. of connected compo
        for(int i=0;i<n;i++){
            if(parent[i]==i)nocc++;
        }

        int ans=nocc-1;
        return extraedge>=ans ? ans : -1;
    }
};