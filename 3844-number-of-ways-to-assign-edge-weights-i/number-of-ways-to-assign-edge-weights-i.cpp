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

        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        int max_depth=0;
        q.push({1,0});
        vector<int>vis(n+1,0);
        vis[1]=1;
        while(!q.empty()){
            auto[node,depth]=q.front();
            q.pop();
            max_depth=max(max_depth,depth);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,depth+1});
                }
            }
        }
      
        vector<int>dp(max_depth+1,-1);
        return rec(max_depth,0,dp);
        

    }
};