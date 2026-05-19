class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));

        bool obstacle=false;
        for(int i=0;i<n;i++){
            if(mat[i][0]==1) obstacle=true;
            if(obstacle)
            dp[i][0]=0;
        }
        obstacle=false;
        for(int i=0;i<m;i++){
            
            if(mat[0][i]==1) obstacle=true;
            if(obstacle)
            dp[0][i]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};