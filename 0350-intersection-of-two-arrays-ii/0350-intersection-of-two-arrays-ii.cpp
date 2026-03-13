class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //onlogn + mlogm
        // int n1=nums1.size();
        // int n2=nums2.size();
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // vector<int> ans;
        // int i=0;
        // int j=0;
        // while(i<n1 && j<n2){
        //     if(nums1[i]==nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        //     else if(nums1[i]<nums2[j])i++;
        //     else j++;
        // }
        // return ans;

        //O(n)
        if(nums1.size()>nums2.size())return intersect(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int> m;
        for(int n:nums1){
            m[n]++;
        }
        vector<int> ans;
        for(int x:nums2){
            if(m[x]>0){
                ans.push_back(x);
                m[x]--;
            }
        }
        return ans;
    }
};