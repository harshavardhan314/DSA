class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        freq=defaultdict(int)
        for i in points:
            x,y=i
            freq[y]+=1
        
        total,ans=0,0
        mod=int(1e9+7)
        for i in freq:
            c=freq[i]
            c=(c*(c-1))//2
            ans=(ans+total*c)%mod
            total= (total+c)%mod
        
        return ans
         
        