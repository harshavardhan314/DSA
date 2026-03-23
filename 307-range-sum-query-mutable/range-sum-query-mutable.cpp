class segmentTree {
public:
    vector<long long> seg, lazy; 
    int n;

        void take_size(int len) {
        n = len;
        seg.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }

    void build(const vector<int>& arr, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; 
    }

    void rangeUpdate(int idx, int low, int high, int l, int r, int val) {
        
        if (lazy[idx] != 0) {
            seg[idx] += (long long)(high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx]; 
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        
        if (low > high || low > r || high < l) return;

        
        if (low >= l && high <= r) {
            seg[idx] += (long long)(high - low + 1) * val;
            if (low != high) {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        
        int mid = (low + high) >> 1;
        rangeUpdate(2 * idx + 1, low, mid, l, r, val);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    long long querySum(int idx, int low, int high, int l, int r) {
        if (lazy[idx] != 0) {
            seg[idx] += (long long)(high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (low > high || low > r || high < l) return 0;
        if (low >= l && high <= r) return seg[idx];

        int mid = (low + high) >> 1;
        return querySum(2 * idx + 1, low, mid, l, r) + querySum(2 * idx + 2, mid + 1, high, l, r);
    }
};





class NumArray {
public:
    
    int n;
    segmentTree st;
    vector<int>vals;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.take_size(n);
        vals=nums;
        st.build(nums,0,0,nums.size()-1);
    }
    
    void update(int idx, int val) {
        int diff=val-vals[idx];
        vals[idx]=val;
        st.rangeUpdate(0,0,n-1,idx,idx,diff);
    }
    
    int sumRange(int l, int r) {
        return st.querySum(0,0,n-1,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */