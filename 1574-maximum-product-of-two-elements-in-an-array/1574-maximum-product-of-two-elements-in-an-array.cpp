class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // return (nums[n-1]-1)*(nums[n-2]-1);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<2;i++){
            pq.push(nums[i]);
        }
        for(int i=2;i<nums.size();i++){
            pq.push(nums[i]);
            pq.pop();
        }
        int a = pq.top()-1;
        pq.pop();
        int b = pq.top()-1;
        pq.pop();
        return a*b;
    }
};