class Disjointset {
    public: vector < int > parent,size;
    
    Disjointset(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int finduparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = finduparent(parent[node]);
    } 
    void unionbysize(int u, int v) {
        int ul_p_u = finduparent(u);
        int ul_p_v = finduparent(v);
        if (ul_p_u == ul_p_v) return;
        if (size[ul_p_u] < size[ul_p_v]) {
            parent[ul_p_u] = ul_p_v;
            size[ul_p_v] += size[ul_p_u];
        }
        else {
            parent[ul_p_v] = ul_p_u;
            size[ul_p_u] += size[ul_p_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {

        Disjointset ds(n);
        int want=n-1;
        int extra=0;
        for(auto it:c){
            int u=it[0];
            int v=it[1];
            if(ds.finduparent(u)==ds.finduparent(v)){
                extra++;
            }
            else{
                ds.unionbysize(u,v);
               want--;
            }
        }
        if(extra>=want)return want;
        return -1;

        
    }
};