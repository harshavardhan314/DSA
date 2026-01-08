class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[[-1]*m for _ in range(n)]
        def rec(i,j):
            if i==n or j==m:
                return 0
            if dp[i][j]!=-1:
                return dp[i][j]
            ans=0
            if s[i]==t[j]:
                ans=1+rec(i+1,j+1)
            else:
                ans=max(rec(i,j+1),rec(i+1,j))
            dp[i][j]=ans
            return ans
        return rec(0,0)
        