class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        int rank=1;
        while(!pq.empty()){
            int val=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(rank==1)ans[index]="Gold Medal";
            else if(rank==2)ans[index]="Silver Medal";
            else if(rank==3)ans[index]="Bronze Medal";
            else ans[index]=to_string(rank);
            rank++;
        }
        // vector<int> copy=score;
        // sort(copy.rbegin(),copy.rend());
        // unordered_map<int,int> m;
        // for(int i=0;i<copy.size();i++){
        //     m[copy[i]]=i+1;
        // }
        // for(int i=0;i<score.size();i++){
        //     int rank= m[score[i]];
        //     if(rank==1)ans.push_back("Gold Medal");
        //     else if(rank==2)ans.push_back("Silver Medal");
        //     else if(rank==3)ans.push_back("Bronze Medal");
        //     else ans.push_back(to_string(rank));
        // }
         return ans;
    }
};