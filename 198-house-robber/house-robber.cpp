int rec(int i,vector<int>&nums,vector<int>&dp){
    int n=nums.size();
    if(i>=n)return 0;
     if(dp[i]!=-1)return dp[i];
    int pick=nums[i]+rec(i+2,nums,dp);
    int not_pick=rec(i+1,nums,dp);

    return dp[i] = max(pick,not_pick);


}

class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][1]=nums[0];
        dp[0][0]=0;
        for(int i=1;i<n;i++){
            // pick
            int pick=nums[i]+dp[i-1][0];

            // not_pick
            int not_pick=dp[i-1][1];
            if(i-2>=0)
            not_pick=max(not_pick,dp[i-2][1]);

            dp[i][1]=pick;
            dp[i][0]=not_pick;
        }
        return max(dp[n-1][1],dp[n-1][0]);
        
    }
};