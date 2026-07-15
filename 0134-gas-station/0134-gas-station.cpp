class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=0;
        int extra=0;
        int lag=0;
        for(int i=0;i<gas.size();i++){
            if(gas[i]+extra<cost[i]){
                lag+= extra+gas[i]-cost[i];
                extra=0;
                s=i+1;
            }
            else extra+= gas[i]-cost[i];
        }
        if(extra+lag>=0)return s;
        return -1;
    }
};