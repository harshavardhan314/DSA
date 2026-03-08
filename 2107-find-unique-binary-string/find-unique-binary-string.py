class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        freq=Counter(nums)
        n=len(nums)
        for i in range(0,2**(n+1)):
            
            val=bin(i)[2:]
            k=n-len(val)
            temp=""
            while k>0:
                temp+='0'
                k-=1
            req=temp+val
            

            if freq[req]==0:
                return req
        
    
        