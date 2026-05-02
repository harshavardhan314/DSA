class Solution {
public:
    long long rob(vector<int >& nums, vector<int >& c) {
        int  n=nums.size();
        vector<vector<long long >>dp(n,vector<long long >(2,0));
        dp[0][1]=nums[0];

        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);

            dp[i][1]=nums[i];

            if(c[i-1]!=c[i])
            dp[i][1]=max(dp[i][1],nums[i]+max(dp[i-1][0],dp[i-1][1]));
            
            if(i-2>=0)
            dp[i][1]=max(dp[i][1],nums[i]+max(dp[i-2][0],dp[i-2][1]));
        }
        return max(dp[n-1][0],dp[n-1][1]);


    }
};