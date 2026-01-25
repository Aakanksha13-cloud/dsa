class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()<k || nums.size()==1)return 0;
        int ans= INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i+k-1<nums.size()){
                int j=i+k-1;
                int currAns= nums[j]-nums[i];
                ans=min(currAns,ans);
            }    
        }
        return ans;
    }
};