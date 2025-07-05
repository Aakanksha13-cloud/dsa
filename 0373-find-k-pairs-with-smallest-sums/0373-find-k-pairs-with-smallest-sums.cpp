class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<>> pq;
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> ans;
        int extract =0;
        while(extract!=k && !pq.empty()){
            vector<int> v =pq.top().second;
            pq.pop();
            int i=v[0];
            int j =v[1];
            ans.push_back({nums1[i],nums2[j]});
            extract++;      
            
            if(j+1<nums2.size())pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return ans;
    }
};