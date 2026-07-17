class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>>pq;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<pair<int,int>>vp={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto it=pq.top();
            int prev_dist=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(i==n-1 && j==m-1){
                return prev_dist;
            }
            pq.pop();
            for(auto [x,y]:vp){
                int ni=i+x;
                int nj=j+y;
                if(ni>=0 && ni<n && nj>=0 && nj<m && max(prev_dist,abs(grid[ni][nj]-grid[i][j])) < dist[ni][nj]){
                    dist[ni][nj]=max(prev_dist,abs(grid[ni][nj]-grid[i][j])); 
                    pq.push({dist[ni][nj],{ni,nj}});

                }
            }
        }
        return 0;
    }
};