bool rec(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    if(i<0){
        if(j<0)return true;
        for(int k=j;k>=0;k--){
            if(p[k]!='*')return false;
        }
        return true;
    }
    if(j<0 && i>=0)return false;

    if(dp[i][j]!=-1) return dp[i][j];
    
    if(p[j]=='?'){
        return dp[i][j]=rec(i-1,j-1,s,p,dp);
    }
    else if(p[j]=='*'){
        
        bool empty_space= rec(i,j-1,s,p,dp);
        bool single_char=rec(i-1,j-1,s,p,dp);
        bool more_than_one=rec(i-1,j,s,p,dp);
        return dp[i][j]=empty_space or single_char or more_than_one; 
    }
    else if(s[i]==p[j]){
        return dp[i][j]=rec(i-1,j-1,s,p,dp);
    }
    else{
        return dp[i][j]=false;
    }
}

class Solution {
public:
    bool isMatch(string s, string p) {

        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return rec(n-1,m-1,s,p,dp);
        
    }
};