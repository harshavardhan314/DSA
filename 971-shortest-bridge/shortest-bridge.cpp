void dfs(int i,int j,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    grid[i][j]=2;
    vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};

    for(auto [x,y]:dir){
        int ni=i+x;
        int nj=j+y;
        if(ni>=0 && ni<n && nj>=0 && nj<m  && grid[ni][nj]==1){
            dfs(ni,nj,grid);
        }
    }
    return;
}

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};

        int sti=0;
        int stj=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){  
                if( grid[i][j]==1){
                    sti=i;
                    stj=j;
                    break;
                }

            }
        }
        dfs(sti,stj,grid);

        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
       

       
        while(!q.empty()){

            auto it=q.front();
            int steps=it.first;
            int i=it.second.first;
            int j=it.second.second;
            
            q.pop();
            for(auto [di,dj]:dir){
                int ni=i+di;
                int nj=j+dj;
                if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj]){
                    vis[ni][nj]=1;
                    if(grid[ni][nj]==2){
                        return steps;
                    }
                    q.push({steps+1,{ni,nj}});


                    
                }
            }

        }
        return 0;
        
    }
};