class Info{
    public:
    int data;
    int row;
    int col;
    Info(int a,int b,int c){
        this->data=a;
        this->row=b;
        this->col=c;
    }
};
class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*,vector<Info*>,compare>pq;
        vector<int> ans;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int val=nums[i][0];
            Info* temp= new Info(nums[i][0],i,0);
            pq.push(temp);
            mini=min(mini,val);
            maxi=max(maxi,val);
        }
        int ans0 = mini;
        int ans1=maxi;
        while(!pq.empty()){
            Info* front=pq.top();
            pq.pop();
            int fdata=front->data;
            int frow=front->row;
            int fcol=front->col;
            mini=fdata;
            if(maxi-mini < ans1-ans0){
               ans0=mini;
               ans1=maxi;
            }
            if(fcol+1<nums[frow].size()){
                Info* temp= new Info(nums[frow][fcol+1],frow,fcol+1);
                pq.push(temp);
                maxi=max(maxi,nums[frow][fcol+1]);
            }
            else break;
        }
        ans.push_back(ans0);
        ans.push_back(ans1);
        return ans;
    }
};