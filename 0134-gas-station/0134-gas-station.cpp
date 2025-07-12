class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int extra=0;
        int lag=0;
        for(int i=0;i<gas.size();i++){
            if(extra+gas[i]<cost[i]){
                lag+=extra+ gas[i]-cost[i];
                extra=0;
                start = i+1;
            }
            else extra+= gas[i]-cost[i];
        }
        if(extra+lag>=0)return start;
        return -1;
    }
};