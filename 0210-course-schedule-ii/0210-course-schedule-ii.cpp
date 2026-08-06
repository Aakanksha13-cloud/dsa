class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        int n=numCourses;
        vector<int> indegree(n,0);
        for(auto a:adj){
            for(int num:a.second)indegree[num]++;  
        }
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto course: adj[top]){
                indegree[course]--;
                if(indegree[course]==0)q.push(course);
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};