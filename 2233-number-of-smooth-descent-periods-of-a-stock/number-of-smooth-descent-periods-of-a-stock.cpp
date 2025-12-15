class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        int l=0;
        int r=1;
        long long int ans=0;
        int n=arr.size();
        for(r=1;r<n;r++)
        {
            if(arr[r-1]!=arr[r]+1)
            {
                long long int t=r-l;
                ans+=(t*(t+1))/2;
                l=r;
            }

        }
        long long int t=r-l;
                ans+=(t*(t+1))/2;
        return ans;
        
    }
};