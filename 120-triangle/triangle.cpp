int rec(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){

    int n=grid.size();
    int m=grid[i].size();
    if(j>=m)return 1e9;

    if(i==n-1){
        return grid[i][j];
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int curr_val=grid[i][j];

    int path1=rec(i+1,j,grid,dp);
    int path2=rec(i+1,j+1,grid,dp);

    return dp[i][j]=curr_val+min(path1,path2);



}
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {

        int n=t.size();

        vector<vector<int>>dp;
        for(int i=0;i<t.size();i++){
            vector<int>v(t[i].size(),1e9);
            dp.push_back(v);
        }
        dp[0][0]=t[0][0];
        for(int i=1;i<n;i++){

            for(int j=0;j<t[i].size();j++){
                if(j<t[i-1].size())
                dp[i][j]=min(dp[i][j],t[i][j]+dp[i-1][j]);
                if(j+1<t[i-1].size())
                dp[i][j+1]=min(dp[i][j+1],t[i][j+1]+dp[i-1][j]);
                if(j>0)
                dp[i][j]=min(dp[i][j],t[i][j]+dp[i-1][j-1]);
            }
        }

        int ans=INT_MAX;

        for(int i=0;i<t[n-1].size();i++){
            ans=min(ans,dp[n-1][i]);
        }
        
        return ans;
    }
};