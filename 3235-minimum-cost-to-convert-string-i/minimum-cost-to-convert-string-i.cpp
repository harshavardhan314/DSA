class Solution {
public:
    long long minimumCost(string s, string t,
                          vector<char>& o,
                          vector<char>& c,
                          vector<int>& cost) {

        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < o.size(); i++) {
            int u = o[i] - 'a';
            int v = c[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }


        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            if (dist[u][v] == INF)
                return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};
