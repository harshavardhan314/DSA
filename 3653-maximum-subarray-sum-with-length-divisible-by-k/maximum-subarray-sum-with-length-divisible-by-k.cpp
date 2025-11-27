class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        long long ans=LONG_LONG_MIN,prefix=0;
        int n=nums.size();
     //   long long  prefix=0;
     vector<long long >remsum(k,LONG_LONG_MAX/2);
     remsum[k-1]=0;
        for (int i=0;i<n;i++)
        {
            prefix+=nums[i];
            ans=max(ans,prefix-remsum[i%k]);
            remsum[i%k]=min(prefix,remsum[i%k]);

        }
        return ans;
        
    }
};