bool check(int mid,vector<vector<pair<long long int,long long int>>>&adj,vector<bool>&online,long long k){
    using T=pair<long long ,long long>;
    priority_queue<T,vector<T>,greater<T>>pq;
    pq.push({0,0});
    int n=online.size();
    vector<long long >dist(n,LONG_MAX);
    dist[0]=0;
    while(!pq.empty()){
        auto[path_sum,node]=pq.top();
        pq.pop();
        if(node==n-1){
            return true;
        }
        if(path_sum>dist[node])continue;

        for(auto [adj_node,adj_sum]:adj[node]){
            int curr_sum=path_sum+adj_sum;
            
            
            if(online[adj_node] && adj_sum>=mid && curr_sum<=k && curr_sum<dist[adj_node]){
                dist[adj_node]=curr_sum;
                pq.push({curr_sum,adj_node});
            }

        }
        
    }
    return false;


}


class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n=online.size();

        vector<vector<pair<long long int,long long int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        long long int l=0;
        long long int h=1e9;
        long long ans=-1;
        while(l<=h){
            long long mid=(l+h)/2;
            if(check(mid,adj,online,k)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
        
        
        
        

        
    }
};