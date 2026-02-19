from sortedcontainers import SortedList

class Solution:
    def minInversionCount(self, nums: list[int], k: int) -> int:
        n = len(nums)
        sl = SortedList()
        inv_cnt = 0
        ans = float('inf')

        for i in range(n):
            if i - k >= 0:
                out_val = nums[i - k]
                smaller = sl.bisect_left((out_val, i-k))
                inv_cnt -= smaller
                sl.remove((out_val, i - k))

            in_val = nums[i]
            greater = len(sl) - sl.bisect_right((in_val, 10**18))
            inv_cnt += greater
            sl.add((in_val, i))

            if i >= k - 1:
                ans = min(ans, inv_cnt)

        return ans