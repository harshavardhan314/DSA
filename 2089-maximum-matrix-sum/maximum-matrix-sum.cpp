class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& v) {
        int n=v.size();
        long long ans=0;
        long long min_val=INT_MAX;
        int neg=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]<0)
                {
                    neg++;
                }
                ans+=abs(v[i][j]);
                min_val=min(min_val,abs(v[i][j])*1LL);
                
            }
        }
        if(neg%2==0)
        {
            return ans;
        }
        return ans-2*min_val;
    }
};