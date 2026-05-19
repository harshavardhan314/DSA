class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                int rem=j-coins[i];
                dp[j]=min(1+dp[rem],dp[j]);
            }
        }
        if(dp[amount]==1e9)return -1;
        return dp[amount];
        
    }
};