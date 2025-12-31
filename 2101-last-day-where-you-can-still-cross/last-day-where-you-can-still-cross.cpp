class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& vis, int n, int m)
    {
        if (i == n - 1) return true;
        vis[i][j] = 1;

        vector<pair<int,int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        for (auto &d : dir)
        {
            int nr = i + d.first;
            int nc = j + d.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                v[nr][nc] == 0 && !vis[nr][nc])
            {
                if (dfs(nr, nc, v, vis, n, m))
                    return true;
            }
        }
        return false;
    }

    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int l = 0, h = cells.size() - 1, ans = 0;

        while (l <= h)
        {
            int mid = (l + h) / 2;

            vector<vector<int>> v(n, vector<int>(m, 0));
            vector<vector<int>> vis(n, vector<int>(m, 0));

            for (int j = 0; j <= mid; j++)
            {
                int r = cells[j][0] - 1;
                int c = cells[j][1] - 1;
                v[r][c] = 1;
            }

            bool ok = false;
            for (int i = 0; i < m; i++)
            {
                if (v[0][i] == 0 && dfs(0, i, v, vis, n, m))
                {
                    ok = true;
                    break;
                }
            }

            if (ok)
            {
                ans = mid+1;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};
