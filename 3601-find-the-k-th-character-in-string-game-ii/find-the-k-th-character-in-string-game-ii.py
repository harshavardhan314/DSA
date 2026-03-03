def rec(n,k,op,i):
    if n==1:
        return "a"
    mid=n//2
    if k<mid:
        return rec(mid,k,op,i-1)
    else:
        val=rec(mid,k-mid,op,i-1)
        if op[i]==1:
            new_val = chr((ord(val) - ord('a') + 1) % 26 + ord('a'))
            return new_val
        return val
class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        n=len(operations)
        length=2**n
        return rec(length,k-1,operations,n-1)

        