class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        res="0"
        for i in range(n):
            if k<=len(res):
                break
            res+="1"
            inv="".join("1" if bit=="0" else "0" for bit in res[:-1])
            res+=inv[::-1]
        return res[k-1]