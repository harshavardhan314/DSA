class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
                else if(grid[i][j]==0)
                {
                    vis[i][j]=1;
                }
                else
                {
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int cnt=-1;
        while(!q.empty())
        {
            int s=q.size();
            cnt++;  
            for(int i=0;i<s;i++){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(auto [x,y]:dir)
                        {
                            int nr=r+x;
                            int nc=c+y;
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
                            {
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                                fresh--;
                            }
                        }
            }
        }
        return fresh==0 ? cnt: -1 ;

        
    }
};