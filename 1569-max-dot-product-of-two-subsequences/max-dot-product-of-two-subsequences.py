class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n,m=len(nums1),len(nums2)
        dp=[[-1]*m for _ in range(n)]
        def rec(i,j):
            if i==n or j==m:
                return -int(1e9)
            if dp[i][j]!=-1:
                return dp[i][j]
            take=nums1[i]*nums2[j]
            skip_j=rec(i,j+1)
            skip_i=rec(i+1,j)
            ans=max(take+rec(i+1,j+1),take,skip_j,skip_i)
            dp[i][j]=ans
            return ans
        return rec(0,0)
            

        