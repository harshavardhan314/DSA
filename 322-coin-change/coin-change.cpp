class Solution {
public:
    int rec(int i, int amount,vector<int>&arr,vector<vector<int>>&dp){
        if(amount == 0 )
        {
            return 0;

        }
        if(i<0||amount<0)
        {
            return INT_MAX;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int pick=rec(i,amount-arr[i],arr,dp);
        if(pick!=INT_MAX)pick+=1;
        int not_pick=rec(i-1,amount,arr,dp);

        return dp[i][amount]=min(pick,not_pick);


    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= rec(n-1,amount,coins,dp);

        return ans==INT_MAX?-1:ans;
        
    }
};