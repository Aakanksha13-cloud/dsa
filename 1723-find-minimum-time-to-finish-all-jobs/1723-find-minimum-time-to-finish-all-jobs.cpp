class Solution {
public:
    bool ispossible(vector<int>& jobs,vector<int>& load,int k,int mid,int i){
        if(i==jobs.size())return true;
        unordered_set<int> s;
        for(int j=0;j<k;j++){
            if(s.count(load[j])>1)continue;
            s.insert(load[j]);
            if(load[j]+jobs[i]>mid)continue;
            load[j]+=jobs[i];
            if(ispossible(jobs,load,k,mid,i+1))return true;
            load[j]-=jobs[i];
            if(load[j]==0)break;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
       sort(jobs.rbegin(),jobs.rend());
       int s=jobs[0];
       int e=accumulate(jobs.begin(),jobs.end(),0);
       int ans=0;
       while(s<=e){
        int mid=s+(e-s)/2;
        vector<int> load(k,0);
        if(ispossible(jobs,load,k,mid,0)){
            ans=mid;
            e=mid-1;
        }
        else  s=mid+1;
       }
       return ans;
    }
};