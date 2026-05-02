int rec(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){

    int n=grid.size();
    int m=grid[0].size();

    if(i==n-1 && j==m-1){
        return 1;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int down=0,right=0;

    if(i+1<n && grid[i+1][j]==0){
        down+=rec(i+1,j,grid,dp);
    }
    if(j+1<m  && grid[i][j+1]==0){
        right+=rec(i,j+1,grid,dp);
    }
    return dp[i][j]=down+right;
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        

        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(grid[0][0]==1)return 0;
        return rec(0,0,grid,dp);
        
    }
};