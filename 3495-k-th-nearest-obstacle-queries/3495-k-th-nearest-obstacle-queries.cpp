class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        
        for(int i=0;i<queries.size();i++){
            int dist = abs(queries[i][0]) + abs(queries[i][1]);
                pq.push(dist);
                if(pq.size()==k){
                   ans.push_back(pq.top());
                }
                else if(pq.size()>k){
                    pq.pop();
                    ans.push_back(pq.top());
                }
                else ans.push_back(-1);
            }
            return ans; 
        
       
    }
};