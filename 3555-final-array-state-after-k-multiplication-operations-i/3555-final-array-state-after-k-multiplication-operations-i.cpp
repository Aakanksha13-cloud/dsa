class compare{
    public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first==b.first)return a.second > b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)return nums;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        int op=0;        
        while(!pq.empty() && op<k){
            auto front = pq.top();
            pq.pop();
            int val = front.first;
            int index= front.second;
            val = val*multiplier;
            pq.push({val,index});
            op++;
        }
        vector<int> ans(nums.size());
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int val = front.first;
            int index= front.second;
            ans[index]=val;
        }
        return ans;
    }
};