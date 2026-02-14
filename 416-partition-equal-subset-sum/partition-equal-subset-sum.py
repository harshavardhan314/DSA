class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        val=sum(nums)
        if val%2!=0:
            return False
        req=val//2
        dp=[False]*(req+1)
        dp[0]=True
        for num in nums:
            for j in range(req,num-1,-1):
                dp[j]=dp[j] or dp[j-num]
        
        return dp[req]


        
        
        




        