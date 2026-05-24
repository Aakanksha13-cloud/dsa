class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool sor=true;
        int n=nums.size();
        int poss=0;
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n]!=(nums[i]+1)%n){
                sor=false;
                break;
            }
            if(nums[i]==0)poss=i;
           
        }
        int ans=INT_MAX;
        if(sor==true){
           
            ans=min(poss,n-poss+2);
        }
        bool rev=true;
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n]!= (nums[i]-1+n)%n){
                rev=false;
                break;
            }
            if(nums[i]==0)poss=i;
        }
        if(rev==true){
            ans=min(ans,min(n-poss,poss+2));
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};