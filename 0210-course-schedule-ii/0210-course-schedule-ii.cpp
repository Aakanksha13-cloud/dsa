class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        int n=numCourses;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
           for(auto a:adj[i]){
            indegree[a]++;
           }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int frontNode=q.front();
            ans.push_back(frontNode);
            q.pop();
            for(auto nbr:adj[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n)return ans ;
        return {};
    }
};