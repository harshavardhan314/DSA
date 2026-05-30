bool rec(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    if(i>=s.size()){
        if(j>=p.size())return true;
        for(int k=j;k<p.size();k++){
            if(p[k]!='*')return false;
        }
        return true;
    }
    if(j>=p.size() && i<s.size())return false;

    if(dp[i][j]!=-1) return dp[i][j];
    
    if(p[j]=='?'){
        return dp[i][j]=rec(i+1,j+1,s,p,dp);
    }
    else if(p[j]=='*'){
        
        bool empty_space= rec(i,j+1,s,p,dp);
        bool single_char=rec(i+1,j+1,s,p,dp);
        bool more_than_one=rec(i+1,j,s,p,dp);
        return dp[i][j]=empty_space or single_char or more_than_one; 
    }
    else if(s[i]==p[j]){
        return dp[i][j]=rec(i+1,j+1,s,p,dp);
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

        return rec(0,0,s,p,dp);
        
    }
};