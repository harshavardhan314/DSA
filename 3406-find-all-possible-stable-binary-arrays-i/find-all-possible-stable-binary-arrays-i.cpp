class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long  M=1e9+7;

        long long dp[201][201][2];
        memset(dp,0,sizeof(dp));

        dp[0][0][0]=1;
        dp[0][0][1]=1;

        for (int z=0;z<=zero;z++){
            for(int o=0;o<=one;o++){

                if (z==0 && o==0)continue;

                for(int i=1;i<=min(o,limit);i++){
                    dp[z][o][0]+=dp[z][o-i][1]%M;
                }
                for(int i=1;i<=min(z,limit);i++){
                    dp[z][o][1]+=dp[z-i][o][0]%M;
                }
            }
        }

        return ( dp[zero][one][1] + dp[zero][one][0] )%M;

        
    }
};