class Solution {
public:
    int rec(int i,vector<int>&nums,vector<int>&dp)
    {
        int n=nums.size();
        if(i>=n)
        return 0;
        if(dp[i]!=-1)return dp[i];

        int pick=nums[i]+rec(i+2,nums,dp);
        int not_pick=rec(i+1,nums,dp);
        return dp[i]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return rec(0,nums,dp);
        
    }
};