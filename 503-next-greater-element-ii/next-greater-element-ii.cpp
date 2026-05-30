class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n=nums.size();
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=(2*n)-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=nums[st.top()] ){
                st.pop();
            }
        
            nge[i%n]=st.empty()?-1:nums[st.top()];
            st.push(i%n);
        }
        return nge;
        
    }
};