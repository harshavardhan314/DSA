class Solution:
    def maxPoints(self, t1: List[int], t2: List[int], k: int) -> int:
        n = len(t1)

        ans = []
        for i in range(n):
            ans.append([t1[i] - t2[i], i, 0])  
        
        ans.sort()
        res = 0

        for i in range(n - k):
            if ans[i][0] < 0:
                ans[i][2] = 1
                idx = ans[i][1]
                res += t2[idx]

        ans = ans[::-1]

        for diff, idx, used in ans:
            if used == 0:
                res += t1[idx]

        return res
