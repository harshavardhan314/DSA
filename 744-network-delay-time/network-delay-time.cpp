class Solution {
public:
    int networkDelayTime(vector<vector<int>>&mat, int n, int k) {
       vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<mat.size();i++){
            int u=mat[i][0];
            int v=mat[i][1];
            int wt=mat[i][2];
            adj[u].push_back({v,wt});
        }
        pq.push({0,k});
        while(!pq.empty()){
            auto[pre_dis,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int edge_wt=it.second;
                int adj_node=it.first;
                if(dist[node]+edge_wt<dist[adj_node]){
                    dist[adj_node]=dist[node]+edge_wt;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX)return -1;
       
        return ans;
        
    }
};