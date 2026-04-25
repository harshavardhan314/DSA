class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n);
        long long mod=1e9+7;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        map<int,int>mp;
        vector<long long int>dist(n,LLONG_MAX);
        vector<long long int>ways(n,0);
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;
        q.push({0,0});
        ways[0]=1;
        while(!q.empty()){
            auto it =q.top();
            long long time=it.first;
            int node=it.second;
            q.pop();
            for(auto it:adj[node]){
                long long int v=it.first;
                long long int d=it.second;
                if(time+d<dist[v]){
                    dist[v]=time+d;
                    ways[v]=ways[node];
                    q.push({time+d,v});
                }
                else if(time+d==dist[v]){
                    ways[v]=(ways[v]%mod+ways[node]%mod)%mod;
                }
            }
        }
       
        return ways[n-1];
        




        
    }
};