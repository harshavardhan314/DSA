class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
       vector<pair<int,int>>vp;
        for(auto it:v){
            int l=it[0];
            int r=it[1];
            int diff=r-l+1;
            vp.push_back({r,l});
        }
        sort(vp.begin(),vp.end());
        int cnt=0;
        int last_val=vp[0].first;
        for(int i=1;i<vp.size();i++){
          int curr_l=vp[i].second;
          if(curr_l<last_val)cnt++;
          else{
            last_val=vp[i].first;
          }

        }
        return cnt;
        
    }
};