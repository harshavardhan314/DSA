class SegTree {
public:
    int n;
    vector<int> seg;
    SegTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0;
        if (l <= low && high <= r) return seg[idx];
        int mid = (low + high) / 2;
        return max(
            query(2*idx+1, low, mid, l, r),
            query(2*idx+2, mid+1, high, l, r)
        );
    }

    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            update(2*idx+1, low, mid, pos, val);
        else
            update(2*idx+2, mid+1, high, pos, val);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegTree seg(baskets);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int l = 0, h = n - 1;
            int ans = -1;

            while (l <= h) {
                int mid = (l + h) / 2;
                if (seg.query(0, 0, n - 1, 0, mid) >= fruits[i]) {
                    ans = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (ans == -1) {
                cnt++; 
            } else {
                seg.update(0, 0, n - 1, ans, 0); 
            }
        }
        return cnt;
    }
};
