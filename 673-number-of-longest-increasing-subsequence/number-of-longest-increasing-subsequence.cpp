class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    if (1+dp[j]>dp[i])
                    {
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    else if(1+dp[j]==dp[i])
                    {
                        cnt[i]+=cnt[j];
                    }
                }
            }
        }
        int ans=1;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                idx=i;
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==ans)
            res+=cnt[i];
            
        }
        return res;
        
    }
};