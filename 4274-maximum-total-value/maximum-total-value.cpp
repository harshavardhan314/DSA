
bool check(long long int mid, vector<int>& val, vector<int>& decay, int m) {
    int n = val.size();
    long long int cnt = 0;
    for (int i = 0; i < n; i++) {

        if (val[i] < mid)
            continue;
        int diff = val[i] - mid;
        cnt += diff / decay[i] + 1;
    }
    return cnt >= m;
}
class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {

        long long int l = 0;
        long long int h = 1e9;
        int threshold = 0;
        int n = value.size();
        while (l <= h) {
            long long int mid = (l + h) / 2;
            if (check(mid, value, decay, m)) {
                threshold = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        long long total_cnt = 0;

        for (int i = 0; i < n; i++) {
            if (value[i] < threshold)
                continue;

            long long diff = value[i] - threshold;
            long long cnt = diff / decay[i] + 1;
            total_cnt += cnt;

            long long curr_sum =
                cnt * (2LL * value[i] - (cnt - 1LL) * decay[i]) / 2;

            ans = (ans + curr_sum % mod) % mod;
        }

        long long rem = total_cnt - m;
        ans = (ans - (rem * threshold) % mod + mod) % mod;
        return ans;
    }
};