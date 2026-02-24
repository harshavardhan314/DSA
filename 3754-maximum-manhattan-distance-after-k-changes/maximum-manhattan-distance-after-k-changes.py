class Solution:
    def maxDistance(self, st: str, k: int) -> int:
        ans=0
        want=["NE","NW","SE","SW"]
        temp=k
        for i in want:
            dis=0
            k=temp
            for j in st:
                if j==i[0] or j==i[1]:
                    dis+=1
                elif k>0:
                    dis+=1
                    k-=1
                else:
                    dis-=1
                ans=max(ans,dis)
        return ans
                
        