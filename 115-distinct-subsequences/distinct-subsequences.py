class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[[-1]*m for _ in range(n)]
        def rec(i,j):
            if i>= len(s) and  j>=len(t):
                return 1
            if i>=n and j<m:
                return 0
            if i<n and j>=m:
                return 1
            if dp[i][j]!=-1:
                return dp[i][j]
            ans=0
            if s[i]==t[j]:
                ans+=rec(i+1,j+1)+rec(i+1,j)
            else:
                ans+=rec(i+1,j)
            dp[i][j]=ans
            return ans
        return rec(0,0)