bool dfs(int node,vector<int>&vis,vector<int>&path_vis,vector<vector<int>>&adj){
    vis[node]=1;
    path_vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,vis,path_vis,adj))return true;
        }
        else if(path_vis[it])return true;
    }
    path_vis[node]=0;
    return false;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<vector<int>>adj(n);
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>path_vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,path_vis,adj))return false;
            }
        }
        return true;
    }
};