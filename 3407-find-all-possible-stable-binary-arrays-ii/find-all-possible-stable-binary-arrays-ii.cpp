


class Solution {
public:
    int numberOfStableArrays(int z, int o, int limit) {

        int dp[1001][1001][2];
        long long M=1e9+7;
        memset(dp,0,sizeof(dp));

        for (int i=0;i<=min(z,limit);i++){
            dp[i][0][0]=1;
        }
        for(int i=0;i<=min(o,limit);i++){
            dp[0][i][1]=1;
        }
        for (int i=0;i<=z;i++){
            for(int j=0;j<=o;j++){
                if(i==0 || j==0)continue;

                dp[i][j][1] =( dp[i][j-1][0] + dp[i][j-1][1] )%M;

                if(j-1>=limit){
                    dp[i][j][1] = ( dp[i][j][1] - dp[i][j-1-limit][0] + M )%M;
                }

                dp[i][j][0] =( dp[i-1][j][0] + dp[i-1][j][1] )%M;

                if(i-1>=limit){
                    dp[i][j][0] = ( dp[i][j][0] - dp[i-1-limit][j][1] + M )%M;
                }
            }
        }

        return  ( dp[z][o][1] + dp[z][o][0] )%M;

        


    }
};