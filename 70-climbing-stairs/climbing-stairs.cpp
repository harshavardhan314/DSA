class Solution {
public:

    int  rec(int i,int n,vector<int>&dp)
    {
        if(i>n)
        {
            return 0;
        }
        if(i==n)return 1;
        if(dp[i]==-1){
        int ways1=rec(i+1,n,dp);
        int ways2=rec(i+2,n,dp);
        return dp[i]=ways1+ways2;
        }
        else
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return rec(0,n,dp);
    }
};