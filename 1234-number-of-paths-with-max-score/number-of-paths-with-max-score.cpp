int find_max_sum(int i,int j,vector<string>&board,vector<vector<vector<int>>>&dp,int sum,int req){
    long long mod=1e9+7;

    if(board[i][j]=='X'){
        return 0;
    }

    if(i==0 && j==0){
        if(sum==req){
            return 1;
        }
        return 0;

    }

    if(dp[i][j][sum]!=-1){
        return dp[i][j][sum];
    }
    int up=0,left=0,diagonal=0;
    if(i-1>=0){
        int val=board[i][j]-'0';
        up+=find_max_sum(i-1,j,board,dp,sum+val,req);
    }
    if(j-1>=0 ){
        int val=board[i][j]-'0';
        left+=find_max_sum(i,j-1,board,dp,sum+val,req);
    }
    if(i-1>=0 && j-1>=0 ){
        int val=board[i][j]-'0';
        diagonal+=find_max_sum(i-1,j-1,board,dp,sum+val,req);

    }
    return dp[i][j][sum]=(up+left+diagonal)%mod;
}

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        board[n-1][n-1]='0';
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        dp[n-1][n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(board[n-1][i]!='X'){
                dp[n-1][i]=dp[n-1][i+1]+(board[n-1][i]-'0');
            }
        }
        for(int i=n-2;i>=0;i--){
            if(board[i][n-1]!='X'){
                dp[i][n-1]=dp[i+1][n-1]+(board[i][n-1]-'0');
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(i==0 && j==0){
                    dp[0][0]=max({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                }
                else if(board[i][j]!='X'){
                    dp[i][j]=max({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})+(board[i][j]-'0');
                }

            }
        }
       cout<<dp[0][0]<<endl;
        if(dp[0][0]<0)return {0,0};
        vector<vector<vector<int>>>dp2(n,vector<vector<int>>(n,vector<int>(2000,-1)));
        int val=find_max_sum(n-1,n-1,board,dp2,0,dp[0][0]);
    
        return {dp[0][0],val};
    }
};