from collections import UserList
from functools import cache
from typing import List
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n=len(values)
        @cache
        def rec(i,j):
            if j-i+1<=2:
                return 0
            res=float('inf')
            for k in range(i+1,j):
                temp=values[k]*values[i]*values[j]+ rec(i,k)+rec(k,j)
                res=min(res,temp)
            return res
        
        return rec(0,n-1)
                        