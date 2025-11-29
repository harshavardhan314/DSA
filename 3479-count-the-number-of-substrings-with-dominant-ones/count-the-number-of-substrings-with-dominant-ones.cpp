
class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n, 0);

        pre[0] = (s[0] == '1');
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + (s[i] == '1');

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j < n) {
                int ones = pre[j] - (i > 0 ? pre[i - 1] : 0);
                int len = j - i + 1;
                int zeros = len - ones;

                long long z2 = 1LL * zeros * zeros;

                if (z2 > ones) {
                    long long need = z2 - ones;
                    j += need;
                    continue;
                }

                ans++;

                int diff = (int)sqrt(ones) - zeros;
                int nextj = j + diff;

                if (nextj >= n) {
                    ans += (n - j - 1);
                    break;
                } else {
                    ans += diff;
                    j = nextj + 1;
                    continue;
                }
            }
        }

        return ans;
    }
};
