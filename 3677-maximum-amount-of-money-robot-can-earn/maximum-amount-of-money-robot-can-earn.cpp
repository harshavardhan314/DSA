

int rec(int i,int j,int cnt,vector<vector<int>>&v,vector<vector<vector<int>>>&dp){
    int n=v.size();
    int m=v[0].size();
    if(i==n-1 && j==m-1){
        if(v[n-1][m-1]>=0)return v[n-1][m-1];
        if(cnt>0) return 0;
        return v[n-1][m-1];

    }
    if(dp[i][j][cnt]!=INT_MIN)return dp[i][j][cnt];
    int right=INT_MIN;
    int down=INT_MIN;
    if(j+1<m)
    right=v[i][j]+rec(i,j+1,cnt,v,dp);
    if(i+1<n)
    down=v[i][j]+rec(i+1,j,cnt,v,dp);

    if(v[i][j]<0){

        if(cnt>0){
            if(j+1<m)
            right=max(right,rec(i,j+1,cnt-1,v,dp));
            if(i+1<n)
            down=max(down,rec(i+1,j,cnt-1,v,dp));
        }

    }
    return  dp[i][j][cnt]=max(right,down);
    




}
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int n=coins.size();
        int m=coins[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return rec(0,0,2,coins,dp);
        
    }
};