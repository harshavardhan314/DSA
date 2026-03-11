class Solution:
    def bitwiseComplement(self, n: int) -> int:
        val=0
        s=bin(n)[2:]
        res=s[::-1]
        total=0
        for i in range(len(res)):
            if res[i]=='1':
                val+=(1<<i)
            total+=(1<<i)
        return total-val
        