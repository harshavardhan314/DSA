bool bfs(int st_node,set<int>st,vector<vector<int>>&adj,vector<int>&vis){
    queue<int>q;
    vis[st_node]=1;
    st.erase(st.find(st_node));
    q.push(st_node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it] && st.find(it)!=st.end()){
                vis[it]=1;
                q.push(it);
                st.erase(st.find(it));
            }
        }
    }
    return st.size()==0;
}

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>&e) {

        int n=nums.size();
        vector<vector<int>>adj(n);
        for(auto it:e){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<(1LL<<n);i++){
            set<int>nodes;
            int val=0;
            int st_node=-1;
            for(int j=0;j<n;j++){
                if(i&(1LL<<j)){
                    st_node=j;
                    nodes.insert(j);
                    val+=nums[j];
                }

            }
            if(val%2==0 && st_node!=-1){
                vector<int>vis(n,0);
                if(bfs(st_node,nodes,adj,vis))ans++;
            }
        }
        return ans;
        
    }
};