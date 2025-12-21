class Solution:
    def minDeletionSize(self, s: List[str]) -> int:
        rows=len(s)
        cols=len(s[0])
        cnt=0
        already_sorted=[0]*rows
        for i in range(cols):
            ok=1
            for j in range(rows-1):
                if not already_sorted[j] and s[j][i]>s[j+1][i]:
                    ok=0
                    cnt+=1
                    break
            if ok:
                for j in range(rows-1):
                    if s[j][i]<s[j+1][i]:
                        already_sorted[j]=1
                    
                
                


        return cnt
    
            


        