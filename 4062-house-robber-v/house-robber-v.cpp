long long rec(int idx,vector<int>&nums,vector<int>&colors, vector<long long> &dp){
    if(idx>=nums.size())return 0;
    if(dp[idx]!=-1) return dp[idx];
    long long take=nums[idx],not_take=0;
    not_take=rec(idx+1,nums,colors,dp);
    if(idx+1<nums.size())
    {
        if(colors[idx]!=colors[idx+1])
        take+=rec(idx+1,nums,colors,dp);
        else
        take+=rec(idx+2,nums,colors,dp);
    }
   
    return dp[idx]=max(take,not_take);
}
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size()+2,-1);
        return rec(0,nums,colors,dp);
        
    }
};