class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        dp=[[ set() for _ in range(m) ] for _ in range(n)]
        dp[0][0].add(grid[0][0])
        for i in range(1,n):
            for j in dp[i-1][0]:
                dp[i][0].add(grid[i][0]^j)
        
        for i in range(1,m):
            for j in dp[0][i-1]:
                dp[0][i].add(grid[0][i]^j)
        
        for i in range(1,n):
            for j in range(1,m):
                for k in dp[i-1][j]:
                    dp[i][j].add(grid[i][j]^k)
                
                for k in dp[i][j-1]:
                    dp[i][j].add(grid[i][j]^k)
        
        val=10000
        for k in dp[n-1][m-1]:
            val=min(val,k)
        
        return val

            
        