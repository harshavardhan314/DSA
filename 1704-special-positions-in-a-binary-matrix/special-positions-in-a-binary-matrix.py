class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        n=len(mat)
        m=len(mat[0])
        ans=0

        for i in range(n):
            for j in range(m):
                if mat[i][j]==1:
                    valid=True
                    for k in range(m):
                        if k!=j and mat[i][k]==1:
                            valid=False
                    
                    for k in range(n):
                        if k!=i and mat[k][j]==1:
                            valid=False
                    
                    if valid:
                        ans+=1
        
        return ans
                            