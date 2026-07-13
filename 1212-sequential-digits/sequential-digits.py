

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res=[]
        for i in range(1,10):
            val=i
            for j in range(i+1,10):
                val=val*10+j
                if val>=low and val<=high:
                    res.append(val)
        
        res.sort()
        
        return res



        