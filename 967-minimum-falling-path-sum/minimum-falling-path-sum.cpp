int dfs(int r,int c,vector<vector<int>>&m,vector<vector<int>>&dp){

    
    
    if(r==m.size()-1){
        return m[r][c];
    }
    if(dp[r][c]!=INT_MIN)return dp[r][c];
    int v1=INT_MAX,v2=INT_MAX,v3=INT_MAX;
    if(r+1<m.size())
    v1=m[r][c]+dfs(r+1,c,m,dp);
    if(r+1<m.size() && c-1>=0)
    v2=m[r][c]+dfs(r+1,c-1,m,dp);
    if(r+1<m.size() && c+1<m.size())
    v3=m[r][c]+dfs(r+1,c+1,m,dp);
    return dp[r][c]=min({v1,v2,v3});
}


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++){
            int val=dfs(0,i,matrix,dp);
            ans=min(ans,val);
        }
        return ans;
        
    }
};