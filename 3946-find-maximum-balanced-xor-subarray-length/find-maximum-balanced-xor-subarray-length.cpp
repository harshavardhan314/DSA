class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
       int ans=0;
       vector<int>prefix(n,0);
       prefix[0]=nums[0]%2==0?1:-1;
       vector<int>xor_pre(n,0);
       xor_pre[0]=nums[0];
       for(int i=1;i<n;i++)
       {
        xor_pre[i]=xor_pre[i-1]^nums[i];
        prefix[i]=prefix[i-1];
        if(nums[i]%2==0)prefix[i]+=1;
        else
        prefix[i]-=1;
       }
       map<pair<int,int>,int>mp;
       mp[{0,0}]=-1;
       for(int i=0;i<n;i++)
       {
        if(mp.find({xor_pre[i],prefix[i]})!=mp.end())
        {
            int val=mp[{xor_pre[i],prefix[i]}];
            ans=max(ans,i-val);
        }
        else
        {
            mp[{xor_pre[i],prefix[i]}]=i;
        }
       }
        return ans;
        
    }
};