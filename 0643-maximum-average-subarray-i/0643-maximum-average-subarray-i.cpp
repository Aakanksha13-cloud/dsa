class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        int i=0;
        int j=k-1;
        double sum=0;
        for(int i=0;i<=j;i++){
            sum+=nums[i];
        }
        ans=sum;
        i++;
        j++;
        while(j<nums.size()){
            sum+=nums[j]-nums[i-1];
            ans=max(sum,ans);
            i++;
            j++;
        }
        double avg = ans/k;
        return avg;
    }
};