class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        freq=Counter(nums)
        n=len(nums)
        for i in nums:
            if freq[i]==n//2:
                return i
        
        