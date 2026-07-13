int rec(int idx,vector<int>&prices,int prev_buy,vector<vector<int>>&dp){


    if(idx==prices.size())return 0;

    if(dp[idx][prev_buy]!=-1)return dp[idx][prev_buy];
    int profit=0;
    if(prev_buy){
        int sell=prices[idx]+rec(idx+1,prices,0,dp);
        int rest=rec(idx+1,prices,prev_buy,dp);
        profit=max({profit,sell,rest});
    }
    else{
        int buy=-prices[idx]+rec(idx+1,prices,1,dp);
        int rest=rec(idx+1,prices,prev_buy,dp);
        profit=max(buy,rest);
    }
    return dp[idx][prev_buy] = profit;

    

}




class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));
        return rec(0,prices,0,dp);
    }
};