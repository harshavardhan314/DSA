class Solution:
    def minFlips(self, s: str) -> int:
        req1=""
        req2=""
        cnt1,cnt2=0,0
        n=len(s)
        ans=n
        s+=s
        for i in range(2*n):
            req1+= '0' if i%2==0 else '1'
            req2+= '1' if i%2==0 else '0'
        for i in range(2*n):
            if s[i]!=req1[i]:
                cnt1+=1
            if s[i]!=req2[i]:
                cnt2+=1
            
            if i>=n:
                if s[i-n]!=req1[i-n]:
                    cnt1-=1
                if s[i-n]!=req2[i-n]:
                    cnt2-=1
            
            if i>=n-1:
                ans=min(ans,cnt1,cnt2)
        return ans
        

        

        
        

        