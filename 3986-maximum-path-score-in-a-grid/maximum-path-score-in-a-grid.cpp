class Solution {
public:
    int rec(int i, int j, int cost, int k,
            vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp) {

        int n = grid.size(), m = grid[0].size();
        if (i == n || j == m) return -1;

        cost += (grid[i][j] > 0);
        if (cost > k) return -1;

        if (i == n-1 && j == m-1)
            return dp[i][j][cost] = grid[i][j];

        if (dp[i][j][cost] != INT_MIN)
            return dp[i][j][cost];

        int right = rec(i, j+1, cost, k, grid, dp);
        int down  = rec(i+1, j, cost, k, grid, dp);

        int best = max(right, down);
        if (best >= 0)
            return dp[i][j][cost] = best + grid[i][j];
        else
            return dp[i][j][cost] = -1;  
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k+1, INT_MIN))
        );
        return rec(0, 0, 0, k, grid, dp);
    }
};
