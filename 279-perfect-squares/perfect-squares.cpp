class Solution {
public:
    int numSquares(int n) {
        set<int>st;
        int val=1;
        while(1){
            if(val*val>2e4)break;
            st.insert(val*val);
            val++;
        }
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(auto it:st){
                int rem=i-it;
                if(rem<0)break;
                int val=i/it; 
                int k=val*it;
                dp[i]=min(dp[i],val+dp[i-k]);

            }
        }
        return dp[n];
    }
};