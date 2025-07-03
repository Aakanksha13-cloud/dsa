class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        // priority_queue<pair<int,int>> pq;
        // int j=1;
        // for(int i=0;i<score.size();i++){
        //     pq.push({score[i],j});
        //     j++;
        // }
        vector<int> copy=score;
        sort(copy.rbegin(),copy.rend());
        unordered_map<int,int> m;
        for(int i=0;i<copy.size();i++){
            m[copy[i]]=i+1;
        }
        for(int i=0;i<score.size();i++){
            int rank= m[score[i]];
            if(rank==1)ans.push_back("Gold Medal");
            else if(rank==2)ans.push_back("Silver Medal");
            else if(rank==3)ans.push_back("Bronze Medal");
            else ans.push_back(to_string(rank));
        }
        return ans;
    }
};