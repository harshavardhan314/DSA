int rec(int idx, vector<int>& prices, int holding,
        vector<vector<vector<int>>>& dp, int trans) {

    if(idx == prices.size() || trans == 2)
        return 0;

    if(dp[idx][holding][trans] != -1)
        return dp[idx][holding][trans];

    if(holding) {
        int sell = prices[idx] + rec(idx+1, prices, 0, dp, trans+1);
        int hold = rec(idx+1, prices, 1, dp, trans);

        return dp[idx][holding][trans] = max(sell, hold);
    }

    int buy = -prices[idx] + rec(idx+1, prices, 1, dp, trans);
    int skip = rec(idx+1, prices, 0, dp, trans);

    return dp[idx][holding][trans] = max(buy, skip);
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(0,prices,0,dp,0);
    }
};