class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        if(intervals.size()==0)return 0;
         sort(intervals.begin(),intervals.end());
        
        long long bulb= (brightness+2)/3;
       //1 bulb-> 3 places will get enlightened
        long long t=0;
        long long currs= intervals[0][0];
        long long curre=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=curre+1){
                curre=max(curre,(long long)intervals[i][1]);
            }
            else{
                t+=curre-currs+1;
                curre=intervals[i][1];
                currs=intervals[i][0];
            }
        }
        t+=curre-currs+1;
        long long ans = t*bulb;
        return ans;
    }
};