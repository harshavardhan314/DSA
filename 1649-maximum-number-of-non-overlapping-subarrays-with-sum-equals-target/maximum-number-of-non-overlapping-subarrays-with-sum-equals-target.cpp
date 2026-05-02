class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<long long int>st;
        st.insert(0);
        int n=nums.size();
        long long int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(st.find(sum-target)!=st.end()){
                ans++;
                st.clear();
                st.insert(0);
                sum=0;
            }
            st.insert(sum);

        }
        return ans;
        
        
    }
};