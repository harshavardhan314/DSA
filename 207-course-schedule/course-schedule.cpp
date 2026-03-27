bool dfs(int st,vector<vector<int>>&adj,vector<int>&vis,vector<int>&path){
    vis[st]=path[st]=1;

    for(auto neigh:adj[st]){
        
        if(!vis[neigh]){
            if(dfs(neigh,adj,vis,path))return true;
        }
        else if(path[neigh])return true;
        
    }
    path[st]=0;
    return false;
}


class Solution {    
public:
    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>>adj(n);

        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path))return false;
            }
        }

        return true;


        
    }
};