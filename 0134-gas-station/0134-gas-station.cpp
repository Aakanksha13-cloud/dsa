class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int extra =0;
        int lag =0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            if(extra+ gas[i]-cost[i]<0){
                lag+= extra+ gas[i]-cost[i];
                ans=i+1;
                extra=0;
            }
            else{
                extra+= gas[i]-cost[i];
            }
        }
        if(extra+lag>=0)return ans;
        else return -1;
        
    }
};