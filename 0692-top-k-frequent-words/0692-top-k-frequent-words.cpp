class compare{
    public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>, compare> pq;
        for(auto &[str,i] : m){
            pq.push({i,str});
            if(pq.size()>k)pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};