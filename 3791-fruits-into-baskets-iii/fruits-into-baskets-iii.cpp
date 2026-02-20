class segmentTree {
public:
    vector<long long> seg;
    int n;

    segmentTree(int _n) {
        this->n = _n;
        seg.resize(4 * n + 1, 0);
    }

    void build(const vector<int>& arr, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int target) {
        if (low == high) {
            seg[idx] = 0;
            return;
        }
        int mid = (low + high) / 2;
        if (target <= mid) update(2 * idx + 1, low, mid, target);
        else update(2 * idx + 2, mid + 1, high, target);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int findLeftmost(int idx, int low, int high, int val) {
        if (seg[idx] < val) return -1; 
        if (low == high) return low;   

        int mid = (low + high) / 2;
        
        if (seg[2 * idx + 1] >= val) {
            return findLeftmost(2 * idx + 1, low, mid, val);
        } else {
            return findLeftmost(2 * idx + 2, mid + 1, high, val);
        }
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        segmentTree st(n);
        st.build(baskets,0,0,n-1);

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            int ans=st.findLeftmost(0,0,n-1,fruits[i]);

            cout<<ans<<endl;
            if (ans == -1) {
                cnt++; 
            } else {
                st.update(0, 0, n - 1, ans); 
            }
        }
        return cnt;
    }
};
