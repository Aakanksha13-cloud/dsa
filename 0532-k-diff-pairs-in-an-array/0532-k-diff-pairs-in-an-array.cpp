class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // onlogn tc o1 sc
        // sort(nums.begin(),nums.end());
        // int s=0;
        // int e=1;
        // int ans=0;
        // while(s<=e && e<nums.size()){
        //    if(s>0 && nums[s]==nums[s-1]){
        //     s++;
        //     continue;
        //    }
        //    if((e<nums.size()-1 && nums[e]==nums[e+1]) || s==e){
        //     e++;
        //     continue;
        //    }
        //    if(abs(nums[e]-nums[s])==k){
        //     ans++;
        //     s++;
        //     e++;
        //    }
        //    else if(abs(nums[e]-nums[s])>k)s++;
        //    else e++;
        // }
        // return ans;

        //on tc on sc
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(k==0){
                if(it.second>1)ans++;
            }
            else if(m.find(it.first - k)!=m.end())ans++;
        }
        return ans;
    }
};