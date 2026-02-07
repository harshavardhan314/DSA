class Solution:
    def minimumDeletions(self, s: str) -> int:
        n=len(s)
        pre=[0]*n
        cnt_b=0
        for i in range(n):
            pre[i]=cnt_b
            if s[i]=='b':
                cnt_b+=1

        suff=[0]*n
        cnt_a=0
        for i in range(n-1,0,-1):
            suff[i]=cnt_a
            if s[i]=='a':
                cnt_a+=1
        total_a=s.count('a')
        total_b=s.count('b')
        ans=min(total_a,total_b)
        for i in range(1,n):
            ans=min(ans,pre[i]+suff[i])
        return ans
