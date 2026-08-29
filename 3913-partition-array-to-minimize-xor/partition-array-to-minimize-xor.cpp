long long int solve(int i,int k,vector<int>&p,vector<vector<int>>&dp){

    int n=p.size();
     if(k==0){
        int last_seg=p[n-1];
        if(i-1>=0)last_seg^=p[i-1];
        return last_seg;
    }

    
    if(dp[i][k]!=-1)return dp[i][k];
    
    long long ans=LONG_MAX;
    

    for(int j=i;j<n-k;j++){
        int curr_seg=p[j];
        if(i-1>=0)curr_seg^=p[i-1];

        ans=min(ans,max(1LL*curr_seg,solve(j+1,k-1,p,dp)));

    }
    return dp[i][k] = ans;

}


class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>p(n);
        vector<vector<int>>dp(n,vector<int>(k,-1));
        for(int i=0;i<n;i++){
            p[i]=nums[i];
            if(i-1>=0)p[i]^=p[i-1];
        }
        return (int)solve(0,k-1,p,dp);
    }
};