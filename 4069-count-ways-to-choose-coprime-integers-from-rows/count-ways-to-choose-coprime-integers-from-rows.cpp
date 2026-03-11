int dp[200][200];
long long solve(int i,int val,vector<vector<int>>&nums){
    int n=nums.size();
    int m=nums[0].size();
    long long mod=1e9+7;

    if(dp[i][val]!=-1) return dp[i][val];
    if(i==n){
        if(val==1){
            return 1;
        }
        return 0;
    }
    long long ways=0;
    for(int j=0;j<m;j++){
        ways=  ( ways + solve(i+1,gcd(val,nums[i][j]),nums) ) % mod;
    }
    return dp[i][val] = ways%mod;

}


class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,mat);
        
    }
};