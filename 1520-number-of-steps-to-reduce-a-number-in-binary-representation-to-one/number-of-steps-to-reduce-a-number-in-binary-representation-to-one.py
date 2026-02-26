class Solution:
    def numSteps(self, s: str) -> int:
        s=s[::-1]
        val=0
        for i in range(len(s)):
            if s[i]=='1':
                val+=(1<<i)
        
        op=0
        while val>1:
            if val%2==0:
                val=val//2
            else:
                val+=1
            op+=1
            
        return op
        