class Solution:
    def maxProfit(self, price: List[int]) -> int:
        n=len(price)
        dp={}
        def rec(i,buy,cnt):
            if i>=n or  cnt>2:
                return 0
            temp=str(buy)+"_"+str(cnt)
            if (i,temp) in dp:
                return dp[(i,temp)]
            if not buy:
                profit=max( -price[i]+rec(i+1,1,cnt+1) , rec(i+1,0,cnt))
            else:
                profit=max(price[i]+rec(i+1,0,cnt), rec(i+1,buy,cnt))
            
            dp[(i,temp)]=profit
            return profit
        
        return rec(0,0,0)
            
        