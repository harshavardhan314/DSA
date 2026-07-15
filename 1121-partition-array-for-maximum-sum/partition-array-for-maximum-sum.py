def solve(i,arr,k,dp):

    n=len(arr)
    curr_max=0
    ans=0
    if i==n:
        return 0
    
    if dp[i]!=-1:
        return dp[i]
    for j in range(i,min(n,i+k)):
        curr_max=max(curr_max,arr[j])
        l=(j-i+1)
        ans=max(ans,l*curr_max+solve(j+1,arr,k,dp))
    
    dp[i]=ans
    
    return ans



class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n=len(arr)
        dp=[ -1  for _ in range(n)]

        return solve(0,arr,k,dp)
        