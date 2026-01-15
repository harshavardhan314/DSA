class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto it:nums)
        st.insert(it);
        int max_cnt=0;
        int cnt=1;
        for(int nums:st)
        {
            int first=nums+1;
            if(st.count(first))
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            max_cnt=max(max_cnt,cnt);

        }
        return max_cnt;

        
    }
};