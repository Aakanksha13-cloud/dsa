class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
       int n=nums.size(); 
       unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        int i=0;
        while(i<n){
            int togo=0;
            while(m[togo]>0){
                togo++;
            }
            if(togo==0){
                ans.push_back(0);
                m[nums[i]]--;
                i++;
                continue;
            }
            unordered_set<int> s;
            while(i<n){
              int curr=nums[i];
              m[curr]--;
              if(curr<togo)s.insert(curr);
               i++;
               if(s.size()==togo)break; 
            }
            ans.push_back(togo);
        }
        return ans;
        
    }
};