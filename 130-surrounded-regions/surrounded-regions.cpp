class Solution {
public:
    void rec(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(auto it:dir)
        {
            int ni=i+it.first;
            int nj=j+it.second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O' && !vis[ni][nj])
            {
                rec(ni,nj,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        rec(i,j,board,vis);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                {
                    board[i][j]='O';
                }
                else
                board[i][j]='X';
            }

        }
        
    }
};