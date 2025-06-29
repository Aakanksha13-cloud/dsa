class compare{
    public:
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first==b.first)return a.second>b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<mat.size();i++){
            int j=0;
            int sum=0;
            while(j<mat[i].size() && mat[i][j]==1){
                sum++;
                j++;
            };
            pq.push({sum,i});
        }
        vector<int> ans;
        while(!pq.empty() && k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};