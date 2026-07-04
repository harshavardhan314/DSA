class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        queue<int>q;
        q.push(1);
        int ans=INT_MAX;
        vector<int>vis(n+1,0);
        vis[1]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto [adj_node,wt]:adj[node]){
                ans=min(ans,wt);
                if(!vis[adj_node]){
                    vis[adj_node]=1;
                    q.push(adj_node);
                }
            }
        }
        return ans;

        
    }
};