bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&res,vector<int>&path_vis,vector<int>&check){
    vis[node]=1;
    path_vis[node]=1;
    check[node]=0;
    for(auto it:graph[node]){

        if(!vis[it]){
            if(dfs(it,graph,vis,res,path_vis,check))return true;
        }
        else if(path_vis[it]){
            return true;
        }
        
    }
    path_vis[node]=0;
    check[node]=1;
    return false;

}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>path_vis(n,0);
        vector<int>res;
        vector<int>vis(n,0);
        vector<int>check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,res,path_vis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i])res.push_back(i);
        }
        return res;

        
    }
};