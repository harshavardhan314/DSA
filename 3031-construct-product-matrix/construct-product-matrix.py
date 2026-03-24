class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        mod=12345
        n,m=len(grid),len(grid[0])
        pro=1
        pre=[[0]*m for _ in range(n)]
        suff=[[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                pre[i][j]=pro
                pro=(pro*grid[i][j])%mod
        
        pro=1
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                suff[i][j]=pro
                pro=(pro*grid[i][j])%mod
        
        
        
        res=[[0]*m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                res[i][j]=(pre[i][j]*suff[i][j])%mod
        
        return res
        