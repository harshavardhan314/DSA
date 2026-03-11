int pre[300];
int dp[300][300];
int  solve(int i,int par,vector<int>&nums){
    int n=nums.size();
    if(par==0){
        int curr_xor=pre[n]^pre[i];
        return curr_xor;
    }
    int ans=INT_MAX;
    if(dp[i][par]!=-1)return dp[i][par];

    for(int j=i;j<=n-1-par;j++){
        int curr_xor=pre[j+1]^pre[i];
        ans=min(ans,max(curr_xor,solve(j+1,par-1,nums)));
    }

    return dp[i][par]=ans;

}



class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        pre[0]=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]^nums[i];
        }
        memset(dp,-1,sizeof(dp));

        return solve(0,k-1,nums);
        
    }
};