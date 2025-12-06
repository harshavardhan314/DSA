class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        dp = [[-1]*(n+1) for _ in range(n)]

        def rec(i, prev):
            if i == n:
                return 0
            
            if dp[i][prev+1] != -1:
                return dp[i][prev+1]
            
            not_pick = rec(i+1, prev)

  
            pick = 0
            if prev == -1 or nums[i] > nums[prev]:
                pick = 1 + rec(i+1, i)

            dp[i][prev+1] = max(pick, not_pick)
            return dp[i][prev+1]

        return rec(0, -1)
