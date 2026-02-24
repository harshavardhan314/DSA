def check(mid,v,m,k):
    n=len(v)
    vis=[0]*n
    for i in range(n):
        if mid>=v[i]:
            vis[i]=1

    adj=0
    ans=0
    for i in range(n):
        if vis[i]==1:
            adj+=1
        else:
            if adj>=k:
                m-=1
            adj=0
        
        if adj>=k:
            m-=1
            adj=0
    
    return m<=0


class Solution:
    def minDays(self, v: List[int], m: int, k: int) -> int:
        l=min(v)
        h=max(v)
        ans=h
        while l<=h:
            mid=(l+h)//2
            if check(mid,v,m,k):
                ans=min(ans,mid)
                h=mid-1
            else:
                l=mid+1
        if ans==h:
            return -1
        return ans

        