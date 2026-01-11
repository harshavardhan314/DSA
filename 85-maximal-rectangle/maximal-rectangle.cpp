class Solution {
public:
    vector<int>find_nse(vector<int>&heights)
    {
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
        return nse;
    }
    vector<int>find_pse(vector<int>&heights)
    {
        int n=heights.size();
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
        return pse;
    }

    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>hist(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                hist[j]++;
                else
                hist[j]=0;
            }
            vector<int>nse=find_nse(hist);
            vector<int>pse=find_pse(hist);
            for(int k=0;k<m;k++)
            {
                int area=(nse[k]-pse[k]-1)*hist[k];
                ans=max(ans,area);

            }


        }

        return ans;

        
    }
};