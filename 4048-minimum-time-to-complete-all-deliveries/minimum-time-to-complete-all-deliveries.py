def can(mid,d,r):
    lcm=(r[0]*r[1])//gcd(r[0],r[1])
    d1=mid-(mid//r[0])
    d2=mid-(mid//r[1])
    rem=mid-mid//lcm
    if d1>=d[0] and d2>=d[1] and rem >= d[0]+d[1]:
        return True
    return False
class Solution:
    def minimumTime(self, d: List[int], r: List[int]) -> int:
        l=1
        h=int(1e15)
        ans=h
        while l<=h:
            mid=(l+h)//2
            if can(mid,d,r):
                ans=mid
                h=mid-1
            else:
                l=mid+1
        
        return ans