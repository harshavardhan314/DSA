class Solution:
    def numSub(self, s: str) -> int:

        ans=0
        cnt=0
        MOD=int(1e9+7)
        for i in s:
            if i=='1':
                cnt+=1
            else:
                ans+=((cnt)*(cnt+1))//2
                cnt=0
        ans+=((cnt)*(cnt+1))//2
        return ans%MOD

        