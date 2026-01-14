class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),parent(n,-1);
        sort(nums.begin(),nums.end());
        int max_len=1,idx=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if (nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=1+dp[j];
                        parent[i]=j;
                    }
                }
            }
            if(dp[i]>max_len)
            {
                max_len=dp[i];
                idx=i;
            }
        }
        vector<int>res;
       
        while(idx!=-1)
        {
            res.push_back(nums[idx]);
            idx=parent[idx];
        }
        return res;
        
        
    }

};