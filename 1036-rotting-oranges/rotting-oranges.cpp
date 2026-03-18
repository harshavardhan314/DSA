class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        int n=grid.size();
        int m=grid[0].size();

        int fresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)fresh++;
            }
        }

        int min=0;

        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty() && fresh>0){
            int sz=q.size();

            for(int i=0;i<sz;i++){

                auto[x,y]=q.front();
                q.pop();
                

                for(int j=0;j<4;j++){
                    int ni=x+dir[j].first;
                    int nj=y+dir[j].second;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        fresh--;
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            min++;
        }
        
        if(fresh==0)return min;
        return -1;
    }
};