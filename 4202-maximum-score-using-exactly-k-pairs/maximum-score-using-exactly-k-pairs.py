class Solution:
    def maxScore(self, nums1, nums2, K):
        n, m = len(nums1), len(nums2)
        NEG_INF = -10**18

        dp = [[[NEG_INF] * (K + 1) for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(n + 1):
            for j in range(m + 1):
                dp[i][j][0] = 0

        for k in range(1, K + 1):
            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    dp[i][j][k] = max(
                        nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1][k - 1],
                        dp[i - 1][j][k],
                        dp[i][j - 1][k]
                    )

        return dp[n][m][K]
