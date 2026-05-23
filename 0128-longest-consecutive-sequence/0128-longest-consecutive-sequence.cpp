class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> m(nums.begin(), nums.end());
        int n=nums.size();
        
        int ans=0;
        for(auto i:m){
            int curr=i;
            if(m.find(curr-1)!=m.end())continue;
            else if(m.find(curr-1)==m.end()){
                int currlen=1;
                int next=curr+1;
                while(m.find(next)!=m.end()){
                    currlen++;
                    next++;
                }
                ans=max(ans,currlen);
            }
        }
        return ans;
    }
};