class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i:arr)m[i]++;
        unordered_set<int> s;
        for(auto it:m){
            if(s.find(it.second)!=s.end())return false;
            else s.insert(it.second);
        }
        return true;
    }
};