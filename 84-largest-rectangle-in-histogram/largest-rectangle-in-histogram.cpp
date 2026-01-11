class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        vector<int>pse(n,0);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[i]<=heights[s.top()])
            {
                s.pop();
            }
            pse[i]=s.empty() ? -1:s.top();
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long area=(nse[i]-pse[i]-1)*heights[i];
            ans=max(ans,area);
        }
        return ans;

        
    }
};