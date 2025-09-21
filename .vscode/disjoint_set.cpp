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


class Solution {
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        Disjointset ds(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int x1 = stones[i][0], y1 = stones[i][1];
                    int x2 = stones[j][0], y2 = stones[j][1];
                    if(x1==x2||y1==y2)
                    {
                        ds.unionbysize(i,j);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]!=i)
            cnt++;
        }
        return cnt;

        
    }
};