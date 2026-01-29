class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    pq.push({0,{i,j}});
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for(auto &p : dir){
                int nx = x + p.first;
                int ny = y + p.second;

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    if(dist[nx][ny] > d + 1){
                        vis[nx][ny] = 1;
                        dist[nx][ny] = d + 1;
                        pq.push({dist[nx][ny], {nx,ny}});
                    }
                }
            }
        }

        return dist;
    }
};
