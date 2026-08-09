class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        for(int i=0;i<n;i++){
            int dist=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist,points[i]});
        }
        vector<vector<int>> ans;
        while(k>0){
            auto t=pq.top();
            ans.push_back(t.second);
            pq.pop();
            k--;
        }
        return ans;
    }
};