class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        l=0
        n=len(matrix)
        r=n-1
        z=len(matrix[0])
        while l<=r:
            mid=(l+r)//2
            if matrix[mid][0]<=target and matrix[mid][z-1]>=target:
                i=0
                j=z-1
                while i<=j:
                    midi=(i+j)//2
                    if matrix[mid][midi]==target:
                        return True
                    elif matrix[mid][midi]<target:
                        i=midi+1    
                    else:
                        j=midi-1
                return False
            elif matrix[mid][0]>target:
                r=mid-1
            else:
                l=mid+1
                    
        return False
                
        