def rotate(mat):
    n=len(mat)
    m=len(mat[0])
    res=[[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            res[j][n-1-i]=mat[i][j]
    
    return res

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        val=mat
        for i in range(4):
            val=rotate(val)
            if val==target:
                return True
        
        return False
        