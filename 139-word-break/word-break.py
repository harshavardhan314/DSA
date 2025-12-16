class Solution:
    def wordBreak(self, s: str, word: List[str]) -> bool:
        def rec(idx,dp):
            if idx>=len(s):
                return True
            if dp[idx]!=-1:
                return dp[idx]
            temp=""
            for i in range(idx,len(s)):
                temp+=s[i]
                if temp in word and rec(i+1,dp):
                    dp[idx]=True
                    return True
            dp[idx]=False
            return False
        dp=[-1]*len(s)
        return rec(0,dp)

        