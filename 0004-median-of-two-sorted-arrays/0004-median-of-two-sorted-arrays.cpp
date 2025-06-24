class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0;
        int j=0;
        while(i <nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }
        double x=(nums1.size()+nums2.size())/2;
        if((nums1.size()+nums2.size())%2 ==0) return (double)(merged[x]+merged[x-1])/2;
        return merged[x];
    }
};