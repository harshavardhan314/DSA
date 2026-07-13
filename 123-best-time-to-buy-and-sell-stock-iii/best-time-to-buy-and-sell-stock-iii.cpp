int rec(int idx,vector<int>&prices,int prev_buy,vector<vector<vector<int>>>&dp,int trans){


    if(idx==prices.size()||trans==2)return 0;

    if(dp[idx][prev_buy][trans]!=-1)return dp[idx][prev_buy][trans];
    if(prev_buy ){
     
        
        int sell=prices[idx]+rec(idx+1,prices,0,dp,trans+1);
        int rest=rec(idx+1,prices,prev_buy,dp,trans);
        return dp[idx][prev_buy][trans]= max(sell,rest);
        // profit=max({profit,sell,rest});
    }
  
        int buy=-prices[idx]+rec(idx+1,prices,1,dp,trans);
        int rest=rec(idx+1,prices,prev_buy,dp,trans);
        return dp[idx][prev_buy][trans]=max(buy,rest);


    

}



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(0,prices,0,dp,0);
    }
};