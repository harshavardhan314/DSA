long long int rec(int idx,vector<int>&coins,int amount,int ans,int cnt){
    if(idx<0){
        if(amount==0){
            return 0;
        }
        return 1e9;
    }
    long long int take=1e9;
    if(coins[idx]<=amount){
        take=1+rec(idx,coins,amount-coins[idx],ans,cnt+1);
    }
    long long int not_take=rec(idx-1,coins,amount,ans,cnt);
    return min(take,not_take);
    
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       

        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int not_take=dp[i-1][j];

                int take=1e9;

                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }

                dp[i][j]=min(take,not_take);

            }
        }
        if(dp[n-1][amount]==1e9)return -1;
        return dp[n-1][amount];

        
    }
};