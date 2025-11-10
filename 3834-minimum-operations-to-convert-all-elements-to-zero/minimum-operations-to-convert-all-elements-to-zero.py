class Solution:
    def minOperations(self, nums: List[int]) -> int:
        stack=[0]
        res=0
        for i in nums:
            while stack and stack[-1]>i:
                stack.pop()
            
            if not stack or  stack[-1] <i:
                res+=1
                stack.append(i)
        
        return res

            
        