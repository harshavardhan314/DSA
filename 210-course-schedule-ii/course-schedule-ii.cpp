void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
    return;
}
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {

        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>res;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(res.size()==n)return res;
        return {};
    }
};