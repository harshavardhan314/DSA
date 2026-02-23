class Solution {
public:
    int mod=1e9+7;
    int rec(int i,vector<int>&pre,vector<int>&nums,int cnt,vector<int>&states,vector<vector<int>>&dp)
    {
    
        int n=nums.size();
        if(i==n-1){
            if(pre[i]==states[cnt]){
                return 1;
            }
            return 0;
        }
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int ways=0;
        if(pre[i]==states[cnt]){
            ways += rec(i+1,pre,nums,(cnt+1)%4,states,dp);
        }

         ways+=rec(i+1,pre,nums,cnt,states,dp);

        return dp[i][cnt]=ways%mod;

        
    }
    
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(5,-1));
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^nums[i];
        }
        vector<int>states={t1,t1^t2,t2,0};
        return rec(0,pre,nums,0,states,dp);
        
    }
};