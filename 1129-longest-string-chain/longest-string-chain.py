class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        dp={}
        sorted_words=sorted(words,key=len)
        for w in sorted_words:
            dp[w]=1
            for i in range(len(w)):
                pre=w[:i]+w[i+1:]
                if pre in dp:
                    dp[w]=max(1+dp[pre],dp[w])
        
        return max(dp.values())
        