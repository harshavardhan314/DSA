int rec(int i,vector<int>&coins,int a,vector<vector<int>>&dp){

    int n=coins.size();

    if(i>=n){
        if(a==0)return 0;
        return 1e9;
    }
    if(dp[i][a]!=-1)return dp[i][a];

    int pick=1e9;
    if(coins[i]<=a){
        pick=1+rec(i,coins,a-coins[i],dp);
    }
    int not_pick=rec(i+1,coins,a,dp);
    return dp[i][a]=min(pick,not_pick);

}

class Solution {
public:
    int coinChange(vector<int>& coins, int a) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(a+1,-1));

        int val=rec(0,coins,a,dp);
        if(val==1e9)return -1;
        return val;
        
    }
};