
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[[0]*2 for _ in range(n)]
        dp[0][0]=nums[0]
        dp[0][1]=nums[0]
        ans=max(dp[0][1],dp[0][1])
        for i in range(1,n):
            dp[i][0] = min(dp[i-1][0]*nums[i],nums[i],dp[i-1][1]*nums[i])
            dp[i][1] = max(dp[i-1][1]*nums[i],nums[i],dp[i-1][0]*nums[i])
            ans=max(ans,dp[i][0],dp[i][1])
        return ans
        