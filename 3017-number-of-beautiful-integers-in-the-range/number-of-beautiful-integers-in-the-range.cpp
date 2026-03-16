int dp[20][2][30][20][20][2];
int solve(string &s,int idx,bool tight,int prev_rem,int even,int odd,int k,bool started){
    if(idx==s.size()){
        if(even==odd && even>0){
            if(prev_rem==0)return 1;
            return 0;
        }
        return 0;
    }

    if(dp[idx][tight][prev_rem][even][odd][started]!=-1)return dp[idx][tight][prev_rem][even][odd][started];

    int ub = tight ? s[idx]-'0':9;

    int  res=0;
    for(int digit=0;digit<=ub;digit++){
        bool next_tight = tight && digit==ub;
        int next_rem=( (prev_rem*10) + digit)%k;

        if(!started)
        {
            if(digit==0)
            {
                res+=solve(s,idx+1,next_tight,next_rem,even,odd,k,false);
            }
            else
            {
                if(digit%2==0)
                {
                    res+=solve(s,idx+1,next_tight,next_rem,even+1,odd,k,true);
                }
                else
                {
                    res+=solve(s,idx+1,next_tight,next_rem,even,odd+1,k,true);
                }
            }
        }
        else
        {
            if(digit%2==0)
            {
                res+=solve(s,idx+1,next_tight,next_rem,even+1,odd,k,true);
            }
            else
            {
                res+=solve(s,idx+1,next_tight,next_rem,even,odd+1,k,true);
            }
        }

    }
    return dp[idx][tight][prev_rem][even][odd][started]=res;

}


class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {

        string s1=to_string(high);
        memset(dp,-1,sizeof(dp));
        int r=solve(s1,0,1,0,0,0,k,false);
        string s2=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        int l=solve(s2,0,1,0,0,0,k,false);
        return r-l;

        
    }
};