class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0]==1)return -1;
        vector<pair<int,int>>vp={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            for(auto [x,y]:vp){
                int ni=i+x;
                int nj=j+y;
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0 && d+1<dist[ni][nj]){
                    dist[ni][nj]=d+1;
                    q.push({dist[ni][nj],{ni,nj}});
                }

            }
        }
        if (dist[n-1][m-1]==INT_MAX) return -1;
        return dist[n-1][m-1];
        return 0;
    }
    
};