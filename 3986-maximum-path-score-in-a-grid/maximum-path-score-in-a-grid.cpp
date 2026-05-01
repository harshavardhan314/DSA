class Solution {
public:
   

    long long solve(int i, int j, vector<vector<int>>& grid, int cost, int k,vector<vector<vector<int>>>&dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (cost > k) return -1e9;

        if (i == n-1 && j == m-1) {
            int newCost = cost + (grid[i][j] > 0);
            if (newCost > k) return -1e9;
            return grid[i][j];
        }

        if (dp[i][j][cost] != -1e9) return dp[i][j][cost];

        int newCost = cost + (grid[i][j] > 0);

        long long right = -1e9, down = -1e9;

        if (j + 1 < m)
            right = grid[i][j] + solve(i, j+1, grid, newCost, k,dp);

        if (i + 1 < n)
            down = grid[i][j] + solve(i+1, j, grid, newCost, k,dp);

        return dp[i][j][cost] = max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1e9)));

        long long res = solve(0, 0, grid, 0, k,dp);

        if (res < 0) return -1;
        return (int)res;
    }
};