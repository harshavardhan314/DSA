class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            nge[i]=st.empty()?n-1:st.top();
            st.push(i);
        }

        long long ans=0;
        int idx=0;
        while(1){
            ans+=1LL*(nge[idx]-idx)*nums[idx];
            idx=nge[idx];

            if(idx==n-1)break;
        }
        return ans;
        
    }
};