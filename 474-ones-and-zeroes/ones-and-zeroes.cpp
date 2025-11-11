class Solution {
public:
    int rec(int idx,vector<string>&str,int m,int n,vector<vector<vector<int>>>&dp)
    {
        int len=str.size();
        // base case
        if(idx>=len)return 0;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        int cnt1=count(str[idx].begin(),str[idx].end(),'1');
        int cnt0=count(str[idx].begin(),str[idx].end(),'0');
        int not_pick=rec(idx+1,str,m,n,dp);

        int pick=0;
        if(cnt1<=n and cnt0<=m)
        {
            pick=1+rec(idx+1,str,m-cnt0,n-cnt1,dp);
        }
        return dp[idx][m][n]=max(pick,not_pick);
        

    }
    int findMaxForm(vector<string>& str, int m, int n) {
        int l=str.size();
        vector<vector<vector<int>>>dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans= rec(0,str,m,n,dp);

        return ans;
        
    }
};