class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        n=len(nums)
        pref=sum(nums)
        suff=1
        for i in range(n-1,-1,-1):
            pref-=nums[i]
            
            if pref<suff:
                return -1
            if pref==suff:
                return i
            suff=suff*nums[i]
        
        return -1