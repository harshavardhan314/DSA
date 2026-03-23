class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        mod=int(1e9+7)
        max_dp=[[0]*m for _ in range(n)]
        min_dp=[[0]*m for _ in range(n)]

        max_dp[0][0]=grid[0][0]
        min_dp[0][0]=grid[0][0]
        for i in range(1,m):
            max_dp[0][i]=grid[0][i]*max_dp[0][i-1]
            min_dp[0][i]=grid[0][i]*max_dp[0][i-1]
        
        for i in range(1,n):
            max_dp[i][0]=grid[i][0]*max_dp[i-1][0]
            min_dp[i][0]=grid[i][0]*max_dp[i-1][0]
        

        for i in range(1,n):
            for j in range(1,m):

                left1=max_dp[i][j-1]*grid[i][j]
                left2=min_dp[i][j-1]*grid[i][j]

                up1=max_dp[i-1][j]*grid[i][j]
                up2=min_dp[i-1][j]*grid[i][j]

                max_dp[i][j]=max(left1,left2,up1,up2)
                min_dp[i][j]=min(left1,left2,up1,up2)
        
        res=max_dp[n-1][m-1]
        if res<0:
            return -1
        return res%mod




        

