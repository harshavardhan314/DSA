class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        set<pair<int,pair<int,int>>>st;
        st.insert({-1,{0,src}});
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({dist,v});
        }
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        int  ans=INT_MAX;
        while(!st.empty()){
            auto it=st.begin();
            int stops=it->first;
            int dist=it->second.first;
            int node=it->second.second;
            st.erase(it);
            
            for(auto it:adj[node]){
                int d=it.first;
                int v=it.second;
                if(dist+d<distance[v] && stops+1<=k){
                    distance[v]=dist+d;
                    st.insert({stops+1,{dist+d,v}});
                }
            
            }
        }

        return distance[dst]==INT_MAX?-1:distance[dst];
        
    }
};