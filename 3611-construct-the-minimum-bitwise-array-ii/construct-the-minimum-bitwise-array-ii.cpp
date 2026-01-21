class Solution {
public:
    int get_val(vector<int>&bits)
    {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(bits[i])
            ans+=(1LL<<i);
        }
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            if( ( val & (val-1) ) == 0)continue;
            vector<int>bits(32,0);
            for(int j=0;j<32;j++)
            {
                if(val & (1LL<<j))
                bits[j]+=1;
            }
            
            int last_idx=0;
            while(last_idx<32 && bits[last_idx]==1)
            {
                last_idx++;
            }
            if(last_idx>0)bits[last_idx-1]=0;
            ans[i]=get_val(bits);
        }
        return ans;
        
    }
};