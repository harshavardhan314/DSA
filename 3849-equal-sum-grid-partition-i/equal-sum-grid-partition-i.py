class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total=0
        n,m=len(grid),len(grid[0])

        for i in range(n):
            for j in range(m):
                total+=grid[i][j]

        curr=0
        for i in range(n):
            for j in range(m):
                curr+=grid[i][j]
            
            if curr*2==total:
                return True
        curr=0
        for i in range(m):
            for j in range(n):
                curr+=grid[j][i]
            
            if curr*2==total:
                return True
        
        return False
            
        

        