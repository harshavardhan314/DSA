class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        num=1
        vals=set()
        cnt=1
        while True:
            rem=num%k
            if rem==0:
                return cnt
            
            if rem in vals:
                return -1
            cnt+=1
            vals.add(rem)
            num=(rem*10)+1
        
        return -1