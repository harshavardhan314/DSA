class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vp;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            vp.push_back({nums[i],i});
        }
        sort(begin(vp),end(vp));
        int ans=0;
        for(int i=0;i<n;i++)
        {
           
            st.insert(vp[i].second);
            if(vp[i].first!=0)ans++;
            
            while(i+1<n && vp[i].first==vp[i+1].first)
            {
                int first=vp[i].second;
                int second=vp[i+1].second;
                auto idx=st.upper_bound(first);
                // oka vela first element ki second index madhyalo neku min element untey u connect extend the subarray right  so break
                if(idx!=st.end()  && *idx<second) break;
                st.insert(second);
                i++;
                
            }


        }
        return ans;
    }
};
