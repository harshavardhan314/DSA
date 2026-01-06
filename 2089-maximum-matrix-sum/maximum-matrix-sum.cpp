class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& v) {
        map<pair<int,int>,int>mp;
        int n=v.size();
        vector<int>vals;
        long long ans=0;
        long long min_val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]<0)
                {
                    vals.push_back(abs(v[i][j]));
                }
                else 
                ans+=v[i][j];
                min_val=min(min_val,abs(v[i][j])*1LL);
            }
        }
        sort(vals.rbegin(),vals.rend());
        long long  rem_sum=accumulate(vals.begin(),vals.end(),0LL);
        if(vals.size()%2==0)
        {
            return ans+rem_sum;
        }
        return ans+(rem_sum-2*min_val);
    }
};