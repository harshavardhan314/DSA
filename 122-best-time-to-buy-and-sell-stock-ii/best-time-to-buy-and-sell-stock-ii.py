class Solution:
    def maxProfit(self, price: List[int]) -> int:
        n=len(price)
        dp=[[0]*2 for _ in range(n+1)]
        # def rec(i,buy):
        #     if i==n:
        #         return 0
        #     if dp[i][buy]!=-1:
        #         return dp[i][buy]
        #     if not buy:
        #         profit = max( -price[i]+rec(i+1,1) , rec(i+1,buy))
        #     else:
        #         profit=max(price[i]+rec(i+1,0) ,rec(i+1,buy) )
        #     dp[i][buy]=profit
        #     return profit
        
        dp[n][1] =  dp[n][0] = 0

        for i in range(n-1,-1,-1):
            for buy in range(2):
                if not buy:
                    profit = max( -price[i]+dp[i+1][1] , dp[i+1][0])
                else:
                    profit = max(price[i]+dp[i+1][0] ,dp[i+1][1] )
                dp[i][buy]=profit
        return dp[0][0]


        