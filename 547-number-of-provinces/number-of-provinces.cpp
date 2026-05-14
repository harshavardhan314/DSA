void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
    return;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& edge) {

        int n=edge.size();
        int counter=0;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(edge[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                counter++;
                dfs(i,adj,vis);
            }
        }

        return counter;



        
    }
};