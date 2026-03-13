class Solution:
    def check(self, mid,  v, req):
        c = 0
        for val in v:

            k=(8*mid)//val
            k+=1
            ans=int(sqrt(k))
            ans=(ans-1)//2
            c +=ans
            
            if c >= req:
                return True
        return c >= req

    def minNumberOfSeconds(self, req: int, v: list[int]) -> int:

       
        l = min(v)
        h = 10**18
        ans = h
        
        while l <= h:
            mid = (l + h) // 2
            if self.check(mid,v, req):
                ans = mid 
                h = mid - 1
            else:
                l = mid + 1
                
        return ans