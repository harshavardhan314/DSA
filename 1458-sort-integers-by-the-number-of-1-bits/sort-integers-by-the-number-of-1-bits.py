class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        res=[]
        for i in arr:
            val=bin(i)[2:].count('1')
            res.append((val,i))
        
        res.sort()
        ans=[]
        for i,j in res:
            ans.append(j)
        return ans 
        