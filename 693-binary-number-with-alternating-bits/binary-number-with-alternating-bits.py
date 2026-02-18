class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bits=bin(n)
        bits=bits[2:]
        print(bits)
        for i in range(len(bits)-1):
            if bits[i]==bits[i+1]:
                return False
        return True
        