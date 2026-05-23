class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int curr=i.first;
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