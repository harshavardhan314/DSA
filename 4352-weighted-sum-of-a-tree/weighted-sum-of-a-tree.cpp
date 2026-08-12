int dfs(int node,vector<int>&p,vector<int>&depth){
    if(p[node]==-1){
        return depth[node];
    }
    if(depth[node]!=-1)return depth[node];
    return depth[node]=dfs(p[node],p,depth)+1;
}


class Solution {
public:
    long long weightedSum(vector<int>& p, vector<int>& nums) {
        int n=p.size();
        vector<int>depth(n,-1);
        depth[0]=1;
        int h=1;
       for(int i=0;i<n;i++){
        h=max(h,dfs(i,p,depth));
       }
        
        long long int ans=0;
        for(int i=0;i<n;i++){
           ans+=1LL * nums[i]*(h-depth[i]+1);
        }
        return ans;
        
        
    }
};