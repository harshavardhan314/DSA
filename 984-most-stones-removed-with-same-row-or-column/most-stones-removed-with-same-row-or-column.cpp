class disjointset{
    public:
    vector<int>parent,size;

    disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findparent(parent[node]);

    }
    void union_by_size(int u,int v){
        int up_u=findparent(u);
        int up_v=findparent(v);
        if(up_u==up_v)return;
        if(size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
            size[up_v]=1;
        }
        else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
            size[up_u]=1;
        }
    }
    int find_max(){
        int ans=0;
    
        for(auto it:size){
            cout<<it<<" ";
            ans+=it-1;
        }
        return ans;
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& s) {
        vector<pair<int,int>>vp;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(s[i][0]==s[j][0] || s[i][1]==s[j][1]){
                        vp.push_back({i,j});
                    }
                }
            }
        }
        disjointset ds(n);
        for(auto [u,v]:vp){
            ds.union_by_size(u,v);
        }
        return ds.find_max();

        
    }
};