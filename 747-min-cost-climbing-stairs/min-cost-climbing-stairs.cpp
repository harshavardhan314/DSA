class Solution {
public:
    int rec(int i,vector<int>&cost,vector<int>&dp)
    {
        int n=cost.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]==-1){
        int one=cost[i]+rec(i+1,cost,dp);
        int two=cost[i]+rec(i+2,cost,dp);
        return dp[i]=min(one,two);
        }else
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        //int st=rec(0,cost);
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(rec(1,cost,dp),rec(0,cost,dp));

    }
};