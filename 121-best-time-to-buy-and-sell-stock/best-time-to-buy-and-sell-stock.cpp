class Solution {
public:
    int maxProfit(vector<int>& prices) {
        set<int>st;
        int n=prices.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            st.insert(prices[i]);
            auto it=st.begin();
            ans=max(ans,prices[i]-*it);


        }
        return ans;
    }
};