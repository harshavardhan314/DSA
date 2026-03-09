mod=int(1e9)+7

def solve(ones,zeros,limit,last_was_one,dp):
    if ones==0 and zeros==0:
        return 1
    
    if dp[ones][zeros][last_was_one]!=-1:
        return dp[ones][zeros][last_was_one]
    
    res=0
    if last_was_one==True:
        for i in range(1,min(zeros,limit)+1):
            res+=solve(ones,zeros-i,limit,False,dp)
    else:
        for i in range(1,min(ones,limit)+1):
            res+=solve(ones-i,zeros,limit,True,dp)
    
    dp[ones][zeros][last_was_one]=res%mod
    return res%mod
class Solution:
    def numberOfStableArrays(self, zeros: int, ones: int, limit: int) -> int:
        dp=[[ [-1 for _ in range(2)]  for _ in range(201) ]  for _ in range(201)]
        return (solve(ones,zeros,limit,True ,dp) + solve(ones,zeros,limit,False,dp))%mod 
        