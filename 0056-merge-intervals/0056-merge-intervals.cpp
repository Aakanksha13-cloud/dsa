class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            
            int sec=ans.back()[1];
            int fir=intervals[i][0];
            if(fir<=sec){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};