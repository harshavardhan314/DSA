class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[[0]*(m+1) for _ in range(n+1)]
        # def rec(idx1,idx2):
        #     if idx1<0 or idx2<0:
        #         return 0
        #     if dp[idx1][idx2]!=-1:
        #         return dp[idx1][idx2]
        #     if s[idx1]==t[idx2]:
        #         match=1+rec(idx1-1,idx2-1)
        #         dp[idx1][idx2]=match
        #         return 1+rec(idx1-1,idx2-1)
        #     not_match=max(rec(idx1-1,idx2),rec(idx1,idx2-1))
        #     dp[idx1][idx2]=not_match
        #     return max(rec(idx1-1,idx2),rec(idx1,idx2-1))
        # longest=rec(n-1,m-1)
        prev=[0]*(m+1)
        curr=[0]*(m+1)
        for i in range(1,n+1):
            for j in range(1,m+1):
                if s[i-1]==t[j-1]:
                    curr[j]=1+prev[j-1]
                else:
                    curr[j]=max(prev[j],curr[j-1])
            prev=list(curr)
        longest = curr[m]
        return n-longest+m-longest
        