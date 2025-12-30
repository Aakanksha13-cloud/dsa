class Solution {
public:
    void dfs(int node,vector<int>& edges,unordered_map<int,bool>& vis,vector<int>& nodeCount,vector<bool>& dfsTracker,int currLength,int &ans){
        if(node==-1)return;
        vis[node]=true;
        dfsTracker[node]=true;
        nodeCount[node]= currLength;
        int nextNode=edges[node];
        if(nextNode!=-1){
            if(!vis[nextNode])dfs(nextNode,edges,vis,nodeCount,dfsTracker,currLength+1,ans);
            else if(dfsTracker[nextNode]){
                int cycleLength= currLength - nodeCount[nextNode]+1;
                ans= max(cycleLength,ans);
            }
        }
        dfsTracker[node]=false;
    }
    int longestCycle(vector<int>& edges) {
        int ans=-1;
        int n=edges.size();
        unordered_map<int,bool> vis;
        vector<int> nodeCount(n+1);
        int currLength=0;
        vector<bool> dfsTracker(n+1,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,edges,vis,nodeCount,dfsTracker,currLength,ans);
        }
        return ans;
    }
};