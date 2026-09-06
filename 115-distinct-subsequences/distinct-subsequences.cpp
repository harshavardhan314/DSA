int dp[1001][1001];
int rec(int i,int j,string s,string t){

    int n=s.size();
    int m=t.size();
    if(i>=n){
        if(j>=m)return 1;
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];

    int ans=0;
    if(s[i]==t[j]){
        ans+=rec(i+1,j+1,s,t)+rec(i+1,j,s,t);
    }
    else{
        ans+=rec(i+1,j,s,t);
    }
    return dp[i][j]=ans;
}
class Solution {
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);
    }
};