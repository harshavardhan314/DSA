class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

      
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [prev_wt, node, cons] = pq.top();
            pq.pop();

           
            if (node == n - 1) {
                return prev_wt;
            }

          
            if (prev_wt > dist[node][cons]) continue;

            for (auto& [child, curr_wt] : adj[node]) {
                
                int next_cons = (labels[node] == labels[child]) ? cons + 1 : 1;

               
                if (next_cons > k) continue;

                
                if (prev_wt + curr_wt < dist[child][next_cons]) {
                    dist[child][next_cons] = prev_wt + curr_wt;
                    pq.push({dist[child][next_cons], child, next_cons});
                }
            }
        }

        return -1;
    }
};