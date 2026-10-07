class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l=0
        n=len(matrix)
        z=len(matrix[0])
        r=0
        while l<n:
            if matrix[l][r]==target:
                return True
            else:
                r+=1
                if r==z:
                    l+=1
                    r=0
        return False