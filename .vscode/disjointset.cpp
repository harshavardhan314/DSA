class Solution {
   class Disjointset {
    public:
        vector<int> parent, size;
        Disjointset(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int finduparent(int node) {
            if(node==parent[node]) return node;
            return parent[node] = finduparent(parent[node]);
        }
        void unionbysize(int u,int v) {
            int ul_p_u = finduparent(u);
            int ul_p_v = finduparent(v);
            if(ul_p_u==ul_p_v) return;
            if(size[ul_p_u] < size[ul_p_v]) {
                parent[ul_p_u] = ul_p_v;
                size[ul_p_v] += size[ul_p_u];
            } else {
                parent[ul_p_v] = ul_p_u;
                size[ul_p_u] += size[ul_p_v];
            }
        }
    };

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        Disjointset ds(n);
        int extra=0;
        for(auto &it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.finduparent(u)==ds.finduparent(v))
            {
                extra++;
            }
            else
            {
                ds.unionbysize(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)cnt++;
        }
        if(extra>=cnt-1)
        return cnt-1;
        
        return -1;




        
    }
};