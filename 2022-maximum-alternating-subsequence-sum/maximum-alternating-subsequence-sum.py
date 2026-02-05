def rec(idx,parity,nums,dp):
    n=len(nums)
    if idx==n:
        return 0
    if dp[idx][parity%2]!=-1:
        return dp[idx][parity%2]

    if parity%2==0:
        take=nums[idx] +rec(idx+1,parity+1,nums,dp)
    else:
        take=-nums[idx] + rec(idx+1,parity+1,nums,dp)
    
    not_take=rec(idx+1,parity,nums,dp)
    dp[idx][parity%2] = max(take,not_take)
    return max(take,not_take)
    
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[[-1]*2 for _ in range(n)]
        return rec(0,0,nums,dp)