class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 10**9 + 7
        
        dp = [[[[-1]*4 for _ in range(4)] for _ in range(4)] for _ in range(n)]
        
        def rec(i, p1, p2, p3):
            if i == n:
                return 1
            
            if dp[i][p1][p2][p3] != -1:
                return dp[i][p1][p2][p3]
            
            ans = 0
            for c1 in range(1, 4):
                if c1 == p1:
                    continue
                for c2 in range(1, 4):
                    if c2 == c1 or c2 == p2:
                        continue
                    for c3 in range(1, 4):
                        if c3 == c2 or c3 == p3:
                            continue
                        ans = (ans + rec(i+1, c1, c2, c3)) % mod
            
            dp[i][p1][p2][p3] = ans
            return ans
        
        return rec(0, 0, 0, 0)
