class Solution:
    def wordBreak(self, s: str, word: List[str]) -> bool:
        def rec(i,dp):
            if i==len(s):
                return True
            if dp[i]!=-1:
                return dp[i]
            for j in range(1,len(s)+1):
                temp=s[i:i+j]
                if temp in word and rec(i+j,dp):
                    dp[i]=True
                    return True
            
            dp[i]=False
            return False
        dp=[-1]*len(s)
        return rec(0,dp)
