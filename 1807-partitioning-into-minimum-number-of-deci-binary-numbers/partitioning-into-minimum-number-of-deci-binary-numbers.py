class Solution:
    def minPartitions(self, n: str) -> int:
        k=int(max(n))
        extra=0
        for i in n:
            val=int(i)
            extra=max(extra,val-k)
        return k+extra

        
        