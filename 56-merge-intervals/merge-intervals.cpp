class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        int prev_st=intervals[0][0];
        int prev_end=intervals[0][1];
        ans.push_back({prev_st,prev_end});
        for(int i=1;i<n;i++){

            int curr_st=intervals[i][0];
            int curr_end=intervals[i][1];
            if(curr_st<=prev_end){
                vector<int>vals=ans.back();
                ans.pop_back();
                curr_st=vals[0];
                curr_end=max(vals[1],curr_end);
            }
              ans.push_back({curr_st,curr_end});
                prev_st=curr_st;
                prev_end=curr_end;



        }
        return ans;
        
    }
};