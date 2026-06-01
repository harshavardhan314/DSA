class Solution {
public:

    int largestRectangle(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n ? 0 : h[i]);

            while (!st.empty() && currHeight <= h[st.top()]) {
                int height = h[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangle(height));
        }

        return ans;
    }
};