class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n,m=len(s),len(p)
        dp=[[-1]*(m+1) for _ in range(n+1)]
        # def rec(i,j):
        #     if i==n and j==m:
        #         return True
        #     if j==m:
        #         return False
        #     if i==n:
        #         for k in range(j,m):
        #             if p[k]!='*':
        #                 return False
        #         return True
        #     if dp[i][j]!=-1:
        #         return dp[i][j]
        #     if p[j]=='?':
        #         val=rec(i+1,j+1)
        #         dp[i][j]=val
        #         return dp[i][j]
        #     if p[j]=='*':
        #         dp[i][j]=rec(i,j+1) or rec(i+1,j)
        #         return dp[i][j]
        #     if s[i]==p[j]:
        #         dp[i][j]=rec(i+1,j+1)
        #         return dp[i][j]
        #     return False
        found =True
        for j  in range(1,m+1):
            if p[j-1]!='*':
                found=False
            dp[0][j]=found
        for i in range(n+1):
            dp[i][0]=False
        dp[0][0]=True
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                if p[j-1]=='?':
                    dp[i][j]=dp[i-1][j-1]
                elif p[j-1]=='*':
                    dp[i][j]=dp[i-1][j] or dp[i][j-1]
                elif s[i-1]==p[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=False


        return dp[n][m]

        