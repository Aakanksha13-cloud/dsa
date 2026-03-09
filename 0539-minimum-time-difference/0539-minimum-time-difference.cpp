class Solution {
public:
    int time(string t){
        int hr = std::stoi(t.substr(0,2));
        int min= std::stoi(t.substr(3,2));
        return hr*60+min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for(string t:timePoints)mins.push_back(time(t));
        sort(mins.begin(),mins.end());
        int ans=INT_MAX;
        for(int i=1;i<mins.size();i++)ans=min(ans,(mins[i]-mins[i-1]));
        int lastdiff= 1440 + mins[0] - mins[mins.size()-1];
        ans= min(ans,lastdiff);
        return ans;
    }
};