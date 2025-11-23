class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        ones=[]
        twos=[]
        ans=0
        for i in nums:
            if i%3==1:
                ones.append(i)
            elif i%3==2:
                twos.append(i)
        
        ones.sort()
        twos.sort()
        total=sum(nums)
        rem=total%3
        if rem==0:
            return total
        if rem==1:
            op1,op2=0,0
            if len(ones)>0:
                op1=total-ones[0]
            if len(twos)>1:
                op2=total-(twos[0]+twos[1])
            
            ans=max(op1,op2)
        
        if rem==2:
            op1,op2=0,0
            if len(twos)>0:
                op1=total-twos[0]
            if len(ones)>1:
                op2=total-(ones[0]+ones[1])
            
            ans=max(op1,op2)
        
        return ans
        
        return ans

        

        