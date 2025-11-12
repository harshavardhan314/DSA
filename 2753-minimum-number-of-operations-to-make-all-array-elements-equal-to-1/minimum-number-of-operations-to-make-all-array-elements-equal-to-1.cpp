class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)cnt++;
        }
        int val=nums[0];
        for(int i=1;i<n;i++)
        {
            val=gcd(val,nums[i]);
        }
        if(cnt>0)return n-cnt;
        if(val>1)return -1;

        int min_len=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int g=0;
            for(int j=i;j<n;j++)
            {
                g=gcd(g,nums[j]);
                if (g==1)
                min_len=min(min_len,j-i+1);
            }
        }
        return min_len+n-2;
        
        
        
    }
};