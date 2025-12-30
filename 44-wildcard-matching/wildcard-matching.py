class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n,m=len(s),len(p)
        dp=[[-1]*m for _ in range(n)]
        def rec(i,j):
            if i==n and j==m:
                return True
            if j==m:
                return False
            if i==n:
                for k in range(j,m):
                    if p[k]!='*':
                        return False
                return True
            if dp[i][j]!=-1:
                return dp[i][j]
            if p[j]=='?':
                val=rec(i+1,j+1)
                dp[i][j]=val
                return dp[i][j]
            if p[j]=='*':
                dp[i][j]=rec(i,j+1) or rec(i+1,j)
                return dp[i][j]
            if s[i]==p[j]:
                dp[i][j]=rec(i+1,j+1)
                return dp[i][j]
            return False
        return rec(0,0)

        