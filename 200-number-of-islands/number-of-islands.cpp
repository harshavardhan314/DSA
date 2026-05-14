void bfs(int st_i,int st_j,vector<vector<char>>&grid,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    q.push({st_i,st_j});

    vector<pair<int,int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(auto [i,j]:dir){
            int ni=i+x;
            int nj=j+y;
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]=='1'){
                vis[ni][nj]=1;
                q.push({ni,nj});
            }
        }
    }
    return ;
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};