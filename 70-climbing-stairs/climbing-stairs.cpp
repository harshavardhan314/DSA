class Solution {
public:
    vector<int>dp;
    int rec(int n){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int step1=rec(n-1);
        int step2=rec(n-2);
        return dp[n] = step1+step2; 
    }
    int climbStairs(int n) {
        dp.assign(100,-1);
        return rec(n);
        
    }
};