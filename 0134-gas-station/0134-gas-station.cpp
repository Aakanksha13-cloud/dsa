class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int extra =0;
        // int lag =0;
        // int ans=0;
        // for(int i=0;i<gas.size();i++){
        //     if(extra+ gas[i]-cost[i]<0){
        //         lag+= extra+ gas[i]-cost[i];
        //         ans=i+1;
        //         extra=0;
        //     }
        //     else{
        //         extra+= gas[i]-cost[i];
        //     }
        // }
        // if(extra+lag>=0)return ans;
        // else return -1;
        
        int start=0;
        int extra=0;
        int lack=0;
        for(int i=0;i<gas.size();i++){
            if(extra+gas[i]<cost[i]){
                lack+=extra+gas[i]-cost[i];
                extra=0;
                start=i+1;
            }
            else{
                extra+=gas[i]-cost[i];
            }
        }
        if(extra+lack>=0)return start;
        else return -1;
    }
};