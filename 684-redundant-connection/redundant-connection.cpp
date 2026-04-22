class Solution {
public:

    bool detect_cycle(int node, int parent, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (detect_cycle(it, node, vis, adj))
                    return true;
            }
            else if (it != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle(int n, vector<vector<int>> &adj) {
        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (detect_cycle(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

           
            adj[u].push_back(v);
            adj[v].push_back(u);

          
            if (hasCycle(n, adj)) {
                return {u, v}; 
            }
        }

        return {};
    }
};