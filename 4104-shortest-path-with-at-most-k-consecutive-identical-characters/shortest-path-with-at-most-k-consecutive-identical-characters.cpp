class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<long long >>dist(n,vector<long long >(k+1,LONG_MAX));
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,1}});
        dist[0][1]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int prev_dist=it.first;
            int node=it.second.first;
            int cons=it.second.second;
            if(node==n-1)return prev_dist;
            if(prev_dist>dist[node][cons])continue;
            for(auto [adj_node,adj_wt]:adj[node]){
                long long int curr_cons=labels[node]==labels[adj_node]?cons+1:1;
                if(curr_cons>k)continue;
                if(prev_dist+adj_wt<dist[adj_node][curr_cons]){
                    
                    dist[adj_node][curr_cons]=prev_dist+adj_wt;
                    pq.push({dist[adj_node][curr_cons],{adj_node,curr_cons}});

                }
            }

        }
       return -1;
        
    }
};