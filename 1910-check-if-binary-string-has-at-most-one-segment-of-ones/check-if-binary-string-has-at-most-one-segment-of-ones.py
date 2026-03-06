class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        cnt=0
        v=[]
        n=len(s)
        i=0
        while i<n:
            if s[i]=='1':
                cnt+=1
            else:
                if cnt>0:
                    v.append(cnt)
                cnt=0
            i+=1
        if cnt>0:
            v.append(cnt)
        
        
        return len(v)<=1
        