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
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        int last=nums.back();
        nums.pop_back();
        int ans1= rec(0,nums,dp);
        for(int i=0;i<n;i++)dp[i]=-1;
        nums.push_back(last);
        int ans2=rec(1,nums,dp);

        return max(ans1,ans2);
        
    }
};