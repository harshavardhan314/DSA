class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[[-1]*m for _ in range(n)]
        def rec(i,j):
            if j<0 and i<0:
                return 0
            if i<0 and j>=0:
                return 1+rec(i,j-1)
            if i>=0 and j<0:
                return 1+rec(i-1,j)
            if dp[i][j]!=-1:
                return dp[i][j]
            if s[i]!=t[j]:
               replace_op=1+rec(i-1,j-1)
               delete_op=1+rec(i-1,j)
               insert_op=1+rec(i,j-1)
               dp[i][j]=min({replace_op,delete_op,insert_op})
               return dp[i][j]
            else:
                dp[i][j]=rec(i-1,j-1)
                return dp[i][j]
        return rec(n-1,m-1)