class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b= pq.top(); pq.pop();
            int diff = abs(a-b);
            if(diff != 0) pq.push(diff);
        }
        if(!pq.empty())return pq.top();
        return 0;
    }
};