def rec(idx,t,s,dp):
    if idx>=len(s):
        return 0
    if dp[idx][t]!=-1:
        return dp[idx][t]
    take= t*s[idx] + rec(idx+1,t+1,s,dp) 
    not_take = rec(idx+1,t,s,dp)
    dp[idx][t]=max(take,not_take)
    return max(take,not_take)
class Solution:
    def maxSatisfaction(self, s: List[int]) -> int:
        s.sort()
        n=len(s)
        dp=[[-1]* (n+1)  for _ in range(n+1)]
        return rec(0,1,s,dp)

        