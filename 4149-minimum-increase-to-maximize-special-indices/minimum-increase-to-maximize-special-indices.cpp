long long  rec(int i,vector<int>&nums,int skip,vector<vector<long long >>&dp){
    int n=nums.size();
    if(i>=n-1)return 0;
    if(dp[i][skip]!=-1)return dp[i][skip];
    long long pick=0,not_pick=LLONG_MAX;
    long long  maxii=max(nums[i-1],nums[i+1]);
    pick=max(0LL,maxii-nums[i]+1)+rec(i+2,nums,skip,dp);
    if(skip<1)
    not_pick=rec(i+1,nums,skip+1,dp);
    return dp[i][skip]=1LL*min(pick,not_pick);
}
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        if(n%2){
            long long ans=0;
            for(int i=1;i<n-1;i+=2){
                ans+=max(0,max(nums[i-1],nums[i+1])+1-nums[i]);
            }
            return ans;
        }
        vector<vector<long long >>dp(n,vector<long long >(2,-1));
        return rec(1,nums,0,dp);


        
    }
};