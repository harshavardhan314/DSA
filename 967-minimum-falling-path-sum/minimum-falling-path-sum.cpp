

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& dp) {

        int n=dp.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i][j]+min({dp[i-1][j] ,dp[i-1][max(0,j-1)],dp[i-1][min(n-1,j+1)]});
                
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};