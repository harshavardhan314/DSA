class Solution:
    def maxProfit(self, k: int, price: List[int]) -> int:
        n=len(price)
        dp=[[[-1]*(k+1) for _ in range(2)] for _ in range(n)]
        def rec(i,buy,cnt):
            if i>=n or  cnt>k:
                return 0
            if  dp[i][buy][cnt]!=-1:
                return dp[i][buy][cnt]
            if not buy:
                profit=max( -price[i]+rec(i+1,1,cnt+1) , rec(i+1,0,cnt))
            else:
                profit=max(price[i]+rec(i+1,0,cnt), rec(i+1,buy,cnt))
            
            dp[i][buy][cnt]=profit
            return profit
        
        return rec(0,0,0)


        