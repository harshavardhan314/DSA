int mod=1e9+7;
int rec(int n,int cnt,vector<int>&dp){
    if(n==0){
        if(cnt%2)return 1;
        return 0;
    }
    if(dp[n]!=-1)return dp[n];

    int choice1=rec(n-1,cnt+1,dp);
    int choice2=rec(n-1,cnt+2,dp);

    return dp[n]=(choice1+choice2)%mod;
}
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n=edges.size();
        vector<vector<int>>adj(n+1);
        map<int,int>mp;
        mp[1]=0;
        int max_depth=0;
        vector<vector<int>>e;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            e.push_back({min(u,v),max(u,v)});

        }
        sort(e.begin(),e.end());
        for(auto it:e){
            int u=it[0];
            int v=it[1];
            mp[v]+=mp[u]+1;
            max_depth=max(max_depth,mp[v]);
        }
        vector<int>dp(max_depth+1,-1);
        return rec(max_depth,0,dp);
        

    }
};