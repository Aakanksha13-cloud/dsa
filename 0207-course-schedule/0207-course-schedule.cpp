class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(auto a:adj){
            for(int nbr:a.second){
               indegree[nbr]++; 
            }    
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<numCourses;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int t=q.front();
            topo.push_back(t);
            q.pop();
            for(auto nbr:adj[t]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
        }
        if(topo.size()==numCourses)return true;
        return false;
    }
};