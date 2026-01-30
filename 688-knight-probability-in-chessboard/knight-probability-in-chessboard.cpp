class Solution {
public:
    double go(int row,int col,int n,int moves,vector<vector<vector<double>>> &dp){
        vector<int>dr={-2,-2,2,2,-1,-1,1,1};
        vector<int>dc={-1,1,-1,1,-2,2,-2,2};
        double ways=0.0;
        if(moves==0)return 1.0;

        if(dp[row][col][moves]!=-1)return dp[row][col][moves];
        for(int i=0;i<8;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n){
               ways += (1.0/8.0) * go(nr,nc,n,moves-1,dp);
            }
        }

        return dp[row][col][moves]=ways;

    }
    double knightProbability(int n, int k, int row, int col) {

        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));

        return go(row,col,n,k,dp);
        
        
    }
};