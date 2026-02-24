class RangeFreqQuery {
public:
    map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int val) {

        int r_pos=upper_bound(mp[val].begin(),mp[val].end(),right)-mp[val].begin();
        int l_pos=lower_bound(mp[val].begin(),mp[val].end(),left)-mp[val].begin();
        return r_pos-l_pos;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */