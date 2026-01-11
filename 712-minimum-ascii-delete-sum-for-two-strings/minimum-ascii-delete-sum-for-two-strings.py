class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n,m=len(s1),len(s2)
        dp=[[-1]*m for _ in range(n)]
        def LCS(i,j):
            if i==n or j==m:
                return 0
            if dp[i][j]!=-1:
                return dp[i][j]
            if s1[i]==s2[j]:
                res=ord(s1[i])+LCS(i+1,j+1)
            else:
                res=max(LCS(i+1,j),LCS(i,j+1))
            dp[i][j]=res
            return res
        val=sum(ord(i) for i in s1)+sum(ord(i) for i in s2)
        return val-2*LCS(0,0)