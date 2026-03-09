def solve(cnt,s,l,r,flatcost,encost):
    cost=flatcost
    ones=cnt[r]-cnt[l]
    if ones>0:
        cost=(r-l)*ones*encost
    if (r-l)%2==0 and ones:
        mid=(r+l)//2
        left=solve(cnt,s,l,mid,flatcost,encost)
        right=solve(cnt,s,mid,r,flatcost,encost)
        cost=min(cost,left+right)
    return cost
class Solution:
    def minCost(self, s: str, encCost: int, flatCost: int) -> int:
        n=len(s)
        cnt=[0]*(n+1)
        for i in range(1,n+1):
            cnt[i]=cnt[i-1]
            if s[i-1]=='1':
                cnt[i] += 1
        
        return solve(cnt,s,0,n,flatCost,encCost)
        



        