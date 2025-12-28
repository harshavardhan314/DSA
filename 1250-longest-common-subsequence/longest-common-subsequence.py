class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        n1,n2=len(s1),len(s2)
        dp=[[-1]*n2 for _ in range(n1)]
        def rec(idx1,idx2):
            if idx1<0 or idx2<0:
                return 0
            if dp[idx1][idx2]!=-1:
                return dp[idx1][idx2]
            if s1[idx1]==s2[idx2]:
                match=1+rec(idx1-1,idx2-1)
                dp[idx1][idx2]=match
                return match
            not_match=max(rec(idx1-1,idx2),rec(idx1,idx2-1))
            dp[idx1][idx2]=not_match
            return not_match
        
        return rec(n1-1,n2-1)