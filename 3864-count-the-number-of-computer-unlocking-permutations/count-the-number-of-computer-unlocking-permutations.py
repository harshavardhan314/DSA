class Solution:
    def countPermutations(self, c: List[int]) -> int:
        ans=1
        mod=int(1e9+7)
        for i in range(1,len(c)):
            if c[i]<=c[0]:
                return 0
            
            ans= (ans%mod * i%mod)%mod
        
        return ans

        