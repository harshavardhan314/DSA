class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        multiset<long long int>st;
        long long ans=INT_MIN;
        int n=nums.size();
        long long  first_val=1LL*nums[0]*nums[m-1];
        ans=first_val;
        st.insert(nums[0]);
        int l=1;
        for(int i=m;i<n;i++)
        {
            st.insert(nums[l]);
            long long val1=nums[i]*(*st.rbegin());
            long long  val2=nums[i]*(*st.begin());
            ans=max({ans,val1,val2});
            l++;

        }
        return ans;

        
    }
};