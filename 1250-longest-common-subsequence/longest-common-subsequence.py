class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        n,m=len(s1),len(s2)
        dp=[[0]*m for _ in range(n)]
        # def rec(idx1,idx2):
        #     if idx1<0 or idx2<0:
        #         return 0
        #     if dp[idx1][idx2]!=-1:
        #         return dp[idx1][idx2]
        #     if s1[idx1]==s2[idx2]:
        #         match=1+rec(idx1-1,idx2-1)
        #         dp[idx1][idx2]=match
        #         return match
        #     not_match=max(rec(idx1-1,idx2),rec(idx1,idx2-1))
        #     dp[idx1][idx2]=not_match
        #     return not_match
        
        if n == 0 or m == 0:
            return 0

        
        found = False
        for i in range(m):
            if s1[0] == s2[i]:
                found = True
            dp[0][i] = 1 if found else 0

        
        found = False
        for i in range(n):
            if s1[i] == s2[0]:
                found = True
            dp[i][0] = 1 if found else 0

        for i in range(1, n):
            for j in range(1, m):
                if s1[i] == s2[j]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[n-1][m-1]
