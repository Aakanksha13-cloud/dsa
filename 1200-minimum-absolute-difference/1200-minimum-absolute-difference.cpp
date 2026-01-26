class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int mindiff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            int j=i-1;
            int diff= abs(arr[i]-arr[j]);
            mindiff=min(mindiff,diff);
        }
        for(int i=1;i<arr.size();i++){
            int j=i-1;
            if(abs(arr[i]-arr[j])==mindiff)ans.push_back({arr[j],arr[i]});
        }
        return ans;
    }
};