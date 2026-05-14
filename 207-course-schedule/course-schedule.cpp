class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int>indeg(n,0);

        vector<vector<int>>adj(n);
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            q.push(i);
        
        }
        if(q.empty())return false;
        
        vector<int>order;
        while(!q.empty()){
            int node=q.front();
            order.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        return n==order.size();
    }
};