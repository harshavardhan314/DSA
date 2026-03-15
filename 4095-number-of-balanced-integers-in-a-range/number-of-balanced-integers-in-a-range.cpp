long long  dp[20][2][200][200];
long long solve(string &s,int idx,bool tight,int even,int odd){
    if(idx==s.size()){
        if(even==odd && even>0){
            return 1;
        }
        return 0;
    }

    if(dp[idx][tight][even][odd]!=-1)return dp[idx][tight][even][odd];

    int ub = tight ? s[idx]-'0' :9;

    long long ans=0;
    for(int digit=0;digit<=ub;digit++){

        bool next_tight = (tight && digit==ub);

        if(idx%2==0)
        ans += solve(s,idx+1,next_tight,even+digit,odd);
        else
        ans+=solve(s,idx+1,next_tight,even,odd+digit);

    }
    return dp[idx][tight][even][odd] = ans;
}

class Solution {
public:
    long long countBalanced(long long low, long long high) {

        string s1=to_string(high);
        string s2=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        long long  right=solve(s1,0,1,0,0);
        memset(dp,-1,sizeof(dp));
        long long  left=solve(s2,0,1,0,0);
        return right - left;
        
    }
};