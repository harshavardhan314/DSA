class Solution:
    def binaryGap(self, n: int) -> int:
        bits=bin(n)[2:]
        ans=0
        prev=-1
        for i in range(len(bits)):
            if bits[i]=='1':
                if prev==-1:
                    prev=i
                else:
                    ans=max(ans,i-prev)
                    prev=i


        return ans        