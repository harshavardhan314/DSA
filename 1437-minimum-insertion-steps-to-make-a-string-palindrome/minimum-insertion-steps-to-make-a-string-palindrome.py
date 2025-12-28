class Solution:
    def minInsertions(self, s: str) -> int:
        n=len(s)
        dp=[[-1]*n for _ in range(n)]
        def rec(st,end):
            if st>=end:
                return 0
            if dp[st][end]!=-1:
                return dp[st][end]
            if s[st]==s[end]:
                match=rec(st+1,end-1)
                dp[st][end]=match
                return match
            not_match=min(1+rec(st,end-1),1+rec(st+1,end))
            dp[st][end]=not_match
            return min(1+rec(st,end-1),1+rec(st+1,end))
        return rec(0,n-1)