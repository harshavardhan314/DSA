def solve(idx,grid,limit,prev_idx,dp,pre):
    m=len(grid[0])

    if idx==m:
        return 0
    
    if dp[idx][prev_idx+1]!=-1:
        return dp[idx][prev_idx+1]


    ans=0
    keep=0

    val=False
    if prev_idx!=-1:
        if pre[prev_idx][idx]:
            val=True

    if prev_idx==-1 or  val:
        keep = 1+max(ans,solve(idx+1,grid,limit,idx,dp,pre))
    
    not_keep=max(ans,solve(idx+1,grid,limit,prev_idx,dp,pre))
    dp[idx][prev_idx+1]=max(keep,not_keep)
    return dp[idx][prev_idx+1]
    


class Solution:
    def maxConsistentColumns(self, grid: List[List[int]], limit: int) -> int:
        m=len(grid[0])
        n=len(grid)

        dp=[[-1]*(m+3) for _ in range(m+3)]

        pre=[[True]*m for _ in range(m)]

        for i in range(m):
            for j in range(m):
                if i!=j:
                    for k in range(n):
                        if abs(grid[k][i]-grid[k][j])>limit:
                            pre[i][j]=False
                            break
                

        return solve(0,grid,limit,-1,dp,pre)
        