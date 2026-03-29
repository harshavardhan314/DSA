def dfs(i,j,grid):
    n,m=len(grid),len(grid[0])
    grid[i][j]="0"
    dir=[(-1,0),(1,0),(0,1),(0,-1)]
    for (x,y) in dir:
        ni=i+x
        nj=j+y
        if ni>=0 and ni<n and nj>=0 and nj<m and grid[ni][nj]!="0":
            dfs(ni,nj,grid)
    return 

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n,m=len(grid),len(grid[0])
        cnt=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]=="1":
                    cnt+=1
                    dfs(i,j,grid)
        
        print(grid)
        
        return cnt
        