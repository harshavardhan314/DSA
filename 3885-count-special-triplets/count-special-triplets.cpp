class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,long long >pre,suff;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            suff[nums[i]]++;
        }
        pre[nums[0]]++;
        long long ans=0;
        long long int mod=1e9+7;
        for(int i=1;i<n-1;i++)
        {
            suff[nums[i]]--;
            if(pre.find(2*nums[i])!=pre.end() && suff.find(2*nums[i])!=suff.end())
            {
                long long  val=(pre[2*nums[i]] * suff[2*nums[i]] *1LL)%mod;
                // cout<<val<<endl;
                ans=(ans+val)%mod;
            }
            pre[nums[i]]++;
        }
        return ans;


        
    }
};