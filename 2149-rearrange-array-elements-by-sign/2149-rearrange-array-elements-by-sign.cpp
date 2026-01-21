class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0;
        int p=0;
        int ne=1;
        while(i<n){
            int sign = (nums[i]<0)?-1:1;
            if(sign==1){
                ans[p]=nums[i];
                p+=2;
            }
            else if(sign==-1){
                ans[ne]=nums[i];
                ne+=2;
            }
            i++;
        }
        return ans;
    }
};