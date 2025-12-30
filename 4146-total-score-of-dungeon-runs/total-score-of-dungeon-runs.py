
class Solution:
    def totalScore(self, hp: int, d: List[int], r: List[int]) -> int:
        n=len(d)
        pre=[0]*(n+1)
        for i in range(1,n+1):
            pre[i]=pre[i-1]+d[i-1]
        ans=0
        for i in range(1,n+1):
            want=r[i-1]-hp+pre[i]
            idx=bisect_left(pre,want,0,i+1)
            idx=min(idx,i)
            ans+=i-idx
        return ans



        