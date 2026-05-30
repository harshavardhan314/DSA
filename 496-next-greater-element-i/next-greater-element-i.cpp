class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums2.size();
        vector<int>nge(n,-1);
        map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                st.pop();
            }
            nge[i]=st.empty()?-1:nums2[st.top()];
            st.push(i);
            mp[nums2[i]]=nge[i];
        }
        vector<int>res;
        for(auto it:nums1){
            res.push_back(mp[it]);
        }
        return res;

        
    }
};