class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        int n= deck.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int> ans(n);
       
        int i=0;
        while(!q.empty() && i<n){
                ans[q.front()]=deck[i];
                q.pop();
                q.push(q.front());
                q.pop();
                i++;
        }
        return ans;
        
    }
};