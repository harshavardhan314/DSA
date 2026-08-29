class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<p.size();i++){
            int u=p[i][0];
            int v=p[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        if(q.empty())return false;
        vector<int>order;
        while(!q.empty()){
            auto node=q.front();
            order.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }
        return n==order.size();


    }
};