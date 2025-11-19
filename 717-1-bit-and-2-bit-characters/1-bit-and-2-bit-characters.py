class Solution:
    def isOneBitCharacter(self, nums: List[int]) -> bool:
        nums.pop()
        while len(nums)>0:
            if nums[0]==0:
                nums.pop(0)
            elif nums[0]==1 and len(nums)>1:
                nums.pop(0)
                nums.pop(0)
            else:
                return False
        return True
       
    


      