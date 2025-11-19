class Solution:
    def findFinalValue(self, nums: List[int], s: int) -> int:
        freq=Counter(nums)
        while True:
            if freq[s]>0:
                s=s*2
            else:
                return s
        return s
        