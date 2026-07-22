class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            if(l<=res.back()[1]){
                res.back()[1]=max(res.back()[1],r);
            }
            else{
                res.push_back({l,r});
            }
        }
        return res;
        
    }
};