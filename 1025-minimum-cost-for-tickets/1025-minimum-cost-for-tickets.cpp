class Solution {
public:
    int rec(vector<int>& days, vector<int>& costs,int i, vector<int>& dp){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int day=days[i];
        int day1=costs[0]+rec(days,costs,i+1,dp);
        int i7=i;
        for(int index=i+1;index<days.size();index++){
            if(days[index]<day+7)i7++;
        }
        int day7 = costs[1]+rec(days,costs,i7+1,dp);
        int i30=i;
        for(int index=i+1;index<days.size();index++){
            if(days[index]<day+30)i30++;
        }
        int day30= costs[2]+rec(days,costs,i30+1,dp);
        int min1 = min(day1,day7);
        dp[i]= min(day30,min1);
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return rec(days,costs,0,dp);
    }
};