class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bot = n - 1;

        while (left <= right && top <= bot) {

            // print the first row..
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // print the last col

            for (int i = top; i <= bot; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // print the bot row

            if (top <= bot) {

                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bot][i]);
                }
                bot--;
            }
            // print the first col..

            if (left <= right) {
                for (int i = bot; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};