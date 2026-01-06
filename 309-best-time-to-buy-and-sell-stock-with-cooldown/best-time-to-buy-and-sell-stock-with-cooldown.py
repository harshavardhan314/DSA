class Solution:
    def maxProfit(self, price: List[int]) -> int:
        n=len(price)
        dp=[ [-1]*3 for _ in range(n)]
        def rec(i,buy):
            if i>=n:
                return 0
            if  dp[i][buy]!=-1:
                return dp[i][buy]
            if buy==0:
                profit=max( -price[i]+rec(i+1,1) , rec(i+1,0))
            elif buy==1:
                profit=max(price[i]+rec(i+1,2), rec(i+1,buy))
            else:
                profit=rec(i+1,0)
            
            dp[i][buy]=profit
            return profit
        
        return rec(0,0)
        