class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        int n=nums.size();
        for(int r=0;r<k;r++)st.insert(nums[r]);
        vector<int>ans;
        ans.push_back(*st.rbegin());
        int l=0;
        int j=1;
        for(int r=k;r<n;r++){
            st.insert(nums[r]);
            st.erase(st.find(nums[l]));
            ans.push_back(*st.rbegin());
            l++;
        }
        return ans;
    }
};