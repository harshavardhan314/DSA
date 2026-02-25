class Solution:
    def maxProfit(self, price: List[int]) -> int:
        n=len(price)
        dp=[0]*n
        min_till=price[0]
        for i in range(1,n):
            if price[i]-min_till>0:
                dp[i]=price[i]-min_till
                min_till=price[i]
            min_till=min(min_till,price[i])
        ans=sum(dp)
        return ans
            
            
            
        