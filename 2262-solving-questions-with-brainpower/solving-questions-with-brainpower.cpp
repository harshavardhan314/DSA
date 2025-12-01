class Solution {
public:
    long long int rec(int i,int n,vector<vector<int>>&q,int ans,vector<long long int>&dp)
    {
        if(i>=n){
            return 0;
        }
        if(dp[i]==-1){
        long long int pick=q[i][0]+rec(i+q[i][1]+1,n,q,ans,dp);
        long long int not_pick=rec(i+1,n,q,ans,dp);
        return dp[i]=max(pick,not_pick);
        }
        else
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long int>dp(n,-1);
        return rec(0,n,q,0,dp);
        
    }
};