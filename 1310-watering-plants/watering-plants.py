class Solution:
    def wateringPlants(self, p: List[int], cap: int) -> int:
        ans=0
        rem=cap
        n=len(p)
        for i in range(n):
            if rem>=p[i]:
                rem-=p[i]
                ans+=1
            else:
                ans+=2*i+1
                rem=cap-p[i]
        return ans
        