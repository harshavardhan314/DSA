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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {

        int n=nums.size();
        Disjointset DSU(n);
        for(auto it:swaps){
            DSU.unionbysize(it[0],it[1]);
           
        }
        map<int,vector<int>>mp;
        map<int,int>odd_count;
        for(int i=0;i<n;i++){
            int parent=DSU.finduparent(i);
            if(i%2)
            odd_count[parent]++;
            mp[parent].push_back(nums[i]);
        }
        long long ans=0;
        for(auto it:mp){
            int parent_node=it.first;
         
            vector<int>vals=it.second;
           
            sort(vals.begin(),vals.end());
            int odd=odd_count[parent_node];
            long long  odd_sum=0,even_sum=0;
            for(int i=0;i<odd;i++){
                odd_sum+=vals[i];
            }
            for(int i=odd;i<vals.size();i++){
                even_sum+=vals[i];
            }
            ans+=even_sum-odd_sum;

        }
        return ans;
        
    }
};