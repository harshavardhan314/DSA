int rec(int i,int state,vector<pair<int,int>>&vals,vector<int>&w,vector<vector<int>>&dp){
    int n=vals.size();
    if(i>=n)return 0;

    if(dp[i][state]!=-1)return dp[i][state];

    

    auto[curr_pos,curr_dis]=vals[i];

    int left=curr_pos-curr_dis;
    int right=curr_pos;
    if(i>0){
        auto[prev_pos,prev_dist]=vals[i-1];
        if(state==1)prev_pos+=prev_dist;
        left=max(left,prev_pos+1);
    }
   
    int l_idx=lower_bound(w.begin(),w.end(),left)-w.begin();
    int r_idx=upper_bound(w.begin(),w.end(),right)-w.begin();
    r_idx--;
    int range=r_idx-l_idx+1;

    int go_left=range+rec(i+1,0,vals,w,dp);

    left=curr_pos;
    right=curr_pos+curr_dis;
    if(i+1<n){
        auto[next_pos,next_dist]=vals[i+1];
        right=min(right,next_pos-1);
        
    }

   
    
    l_idx=lower_bound(w.begin(),w.end(),left)-w.begin();
    r_idx=upper_bound(w.begin(),w.end(),right)-w.begin();
    r_idx--;
    range=r_idx-l_idx+1;

    int go_right=range+rec(i+1,1,vals,w,dp);

    return dp[i][state]=max(go_left,go_right);



}
class Solution {
public:
    int maxWalls(vector<int>& r, vector<int>& d, vector<int>& w) {

        vector<pair<int,int>>vals;
        int n=r.size();
        for(int i=0;i<n;i++){
            vals.push_back({r[i],d[i]});
        }
        sort(vals.begin(),vals.end());
        sort(w.begin(),w.end());
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return rec(0,2,vals,w,dp);
       

        
        
    }
};