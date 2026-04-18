class Solution:
    def mirrorDistance(self, n: int) -> int:
        val=str(n)
        rev_val=val[::-1].lstrip('0')
        return abs(n-int(rev_val))
        