class Solution {
public:
    bool ispossible(vector<int>& jobs,vector<int>& load, int k,int mid,int index){
        if(index==jobs.size())return true;
        unordered_set<int> alreadyoccured;
        for(int i=0;i<k;i++){
            if(alreadyoccured.count(load[i]))continue;
            alreadyoccured.insert(load[i]);
            if(load[i]+jobs[index]>mid)continue;
            load[i]+=jobs[index];
            if(ispossible(jobs,load,k,mid,index+1))return true;
            load[i]-=jobs[index];
            if(load[i]==0)break;
            
        }
    return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(),jobs.rend());
        int s=jobs[0];
        int e=accumulate(jobs.begin(),jobs.end(),0);
        if(k==1)return e;
        int maxtime=e;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            vector<int> load(k,0);
            if(ispossible(jobs,load,k,mid,0)){
                maxtime=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return maxtime;
    }
};