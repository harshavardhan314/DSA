class segmentTree {
public:
    vector<long long> seg, lazy; 
    int n;

    segmentTree(int _n) {
        this->n = _n;
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

    void rangeUpdate(int idx, int low, int high, int l, int r) {
        
        if (lazy[idx] != 0) {
            seg[idx] += 1-seg[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx]; 
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        
        if (low > high || low > r || high < l) return;

        
        if (low >= l && high <= r) {
            seg[idx] = 1-seg[idx];
            if (low != high) {
                lazy[2 * idx + 1] += 1-seg[idx];
                lazy[2 * idx + 2] += 1-seg[idx];
            }
            return;
        }

        
        int mid = (low + high) >> 1;
        rangeUpdate(2 * idx + 1, low, mid, l, r);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r);
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




class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& q) {

        int n=s.size();
        vector<int>ans;

        vector<int>arr(n,0);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                arr[i]=1;
            }
            else
            arr[i]=0;

        }
        segmentTree st(n);
        st.build(arr,0,0,n-1);

        for(auto it:q){
            if(it[0]==2){
                int l=it[1],r=it[2];
                int res=st.querySum(0,0,n-1,l+1,r);
                ans.push_back(res);
            }
            else{
                int idx=it[1];
                st.rangeUpdate(0,0,n-1,idx,idx);
                if(idx+1<n){
                    st.rangeUpdate(0,0,n-1,idx+1,idx+1);
                }
            }
        }

        return ans;


        
    }
};