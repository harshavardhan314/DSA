class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        nums=nums[::-1]
        val=0
        j=0
        for i in nums:
            val+=i*pow(2,j)
            j+=1
        
       
        res=[]
        i=0
        while i<len(nums):
            if val%5==0:
                res.append(True)
            else:
                res.append(False)
            val=val>>1
            i+=1
        
        res=res[::-1]
        return res


        