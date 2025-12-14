class Solution:
    def countOdds(self, low: int, high: int) -> int:
        ans=0
        if low%2!=0:
            ans+=1
            low+=1
        if high%2!=0:
            ans+=1
            high-=1
        
        r=high-low+1
        ans+=(r)//2
        return ans
        