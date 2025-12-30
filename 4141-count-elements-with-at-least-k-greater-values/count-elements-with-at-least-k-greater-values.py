from collections import Counter
from typing import List

class Solution:
    def countElements(self, nums: List[int], k: int) -> int:
        mp = Counter(nums)
        temp = sorted(mp.keys())
        total = len(nums)
        ans = 0
        prefix = 0

        for x in temp:
            rem = total - mp[x] - prefix
            if rem >= k:
                ans += mp[x]
            prefix += mp[x]

        return ans
