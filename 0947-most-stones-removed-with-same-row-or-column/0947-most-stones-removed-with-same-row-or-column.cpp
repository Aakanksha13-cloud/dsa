class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        const int OFFSET = 10001;
 
        for(auto &s:stones){
            adj[s[0]].push_back(s[1]+OFFSET);
            adj[s[1]+OFFSET].push_back(s[0]);
        }

        int compo=0;
        for(auto &s:stones){
            int node=s[0];
            if(visited.count(node))continue;
            compo++;
            queue<int> q;
            q.push(node);
            visited.insert(node);
            while(!q.empty()){
               int curr=q.front();
               q.pop();
               for(auto nbr:adj[curr]){
                if(!visited.count(nbr)){
                    visited.insert(nbr);
                    q.push(nbr);
                }
               }
            }
        }
        return stones.size()-compo;
    }
};