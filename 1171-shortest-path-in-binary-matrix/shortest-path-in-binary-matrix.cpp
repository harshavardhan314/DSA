class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));

        if(grid[0][0]==1)return -1;

        q.push({1,{0,0}});
        vis[0][0]=1;
        while(!q.empty()){
            int steps=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(i==n-1 and j==n-1)return steps;
            for(auto [x,y]:dir){
                int ni=i+x;
                int nj=j+y;
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj]!=1){
                    vis[ni][nj]=1;
                    q.push({steps+1,{ni,nj}});
                }
            }

        }
        return -1;

        
    }
};