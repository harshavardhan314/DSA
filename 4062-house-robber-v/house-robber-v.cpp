long long int  solve( int  i,vector< int >&nums,vector< int >&c,vector<long long int >&dp){
    long long int  n=nums.size();
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    long long int  pick=nums[i]+solve(i+2,nums,c,dp);
    long long int  next_cost=0;
    if(i+1<n && c[i]!=c[i+1]){
        next_cost=nums[i]+solve(i+1,nums,c,dp);
    }
    long long int  not_pick=solve(i+1,nums,c,dp);
    return dp[i]=max({pick,not_pick,next_cost});
}




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