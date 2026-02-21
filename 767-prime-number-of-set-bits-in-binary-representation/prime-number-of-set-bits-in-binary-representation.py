def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans=0
        for i in range(left,right+1):
            if is_prime(bin(i)[2:].count('1')):
                ans+=1
        return ans
        