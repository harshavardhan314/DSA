class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        if(fresh==0)return 0;

        vector<pair<int,int>>vp={{-1,0},{1,0},{0,1},{0,-1}};
        int time=-1;

        while(!q.empty() ){
            int s=q.size();
            time++;
            for(int i=0;i<s;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto [di,dj]:vp){
                    int ni=x+di;
                    int nj=y+dj;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        q.push({ni,nj});
                        grid[ni][nj]=2;
                        fresh--;
                    }
                }
            }
            
        }   
        if(fresh>0)return -1;

        return time;     
    }
};