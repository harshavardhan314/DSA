class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {'1': 0}
        ans = 0

        for i in range(len(s)):
            if s[i] == '1':
                f = d['1']
                ans = ans + f + 1
                d['1'] = f + 1
            else:
                d['1'] = 0

        return ans % (10**9 + 7)