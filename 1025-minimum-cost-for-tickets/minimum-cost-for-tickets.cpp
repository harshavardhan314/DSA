int rec(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp){

    int n=days.size();
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=INT_MAX)return dp[idx];
    int curr_day=days[idx];

    int next_idx_1=upper_bound(days.begin(),days.end(),curr_day)-days.begin();
    int one_day_pass=costs[0] + rec(next_idx_1,days,costs,dp);
    int next_idx_2=upper_bound(days.begin(),days.end(),curr_day+6)-days.begin();
    int seven_day_pass=costs[1] + rec(next_idx_2,days,costs,dp);
    int next_idx_3=upper_bound(days.begin(),days.end(),curr_day+29)-days.begin();
    int thrity_day_pass=costs[2] +rec(next_idx_3,days,costs,dp);

    return dp[idx] = min({one_day_pass,seven_day_pass,thrity_day_pass});

}
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n=days.size();
        vector<int>dp(n,INT_MAX);
        return rec(0,days,costs,dp);
    }
};