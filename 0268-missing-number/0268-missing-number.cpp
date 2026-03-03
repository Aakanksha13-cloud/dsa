class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //onlogn
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=i)return i;
        // }
        // return n;

        //on
        //cox xor of a,a=0 or cancels out..so only missing one remains
        int ans=nums[0];
        for(int i=1;i<n;i++){
            ans^=nums[i];
        }
        for(int i=0;i<=n;i++){
            ans^=i;
        }
        return ans;
    }
};