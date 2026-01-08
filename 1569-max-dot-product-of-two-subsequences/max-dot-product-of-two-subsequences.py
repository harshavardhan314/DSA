class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n,m=len(nums1),len(nums2)
        dp=[[0]*(m+1) for _ in range(n+1)]
        for i in range(m+1):
            dp[0][i]=-int(1e9)
        for i in range(n+1):
            dp[i][0]=-int(1e9)
        for i in range(1,n+1):
            for j in range(1,m+1):
                take=nums1[i-1]*nums2[j-1]
                skip_j=dp[i][j-1]
                skip_i=dp[i-1][j]
                dp[i][j]=max(take,take+dp[i-1][j-1],skip_i,skip_j)
        return dp[n][m]
            

        