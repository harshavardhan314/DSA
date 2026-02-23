class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        val=set()
        n=len(s)
        for i in range(n):
            if i+k-1<n:
                val.add(s[i:i+k])
        return len(val)==2**k


        