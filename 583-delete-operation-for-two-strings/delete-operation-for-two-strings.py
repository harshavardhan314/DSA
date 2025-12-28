class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[[-1]*m for _ in range(n)]
        def rec(idx1,idx2):
            if idx1<0 or idx2<0:
                return 0
            if dp[idx1][idx2]!=-1:
                return dp[idx1][idx2]
            if s[idx1]==t[idx2]:
                match=1+rec(idx1-1,idx2-1)
                dp[idx1][idx2]=match
                return 1+rec(idx1-1,idx2-1)
            not_match=max(rec(idx1-1,idx2),rec(idx1,idx2-1))
            dp[idx1][idx2]=not_match
            return max(rec(idx1-1,idx2),rec(idx1,idx2-1))
        longest=rec(n-1,m-1)
        return n-longest+m-longest
        