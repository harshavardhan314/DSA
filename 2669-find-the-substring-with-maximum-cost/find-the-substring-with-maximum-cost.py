class Solution:
    def maximumCostSubstring(self, s: str, c: str, v: List[int]) -> int:
        mp={}
        n=len(c)
        for i in range(n):
            mp[c[i]]=v[i]
        for i in range(0,27):
            ch=chr(i+ord('a'))
            if ch not in mp:
                mp[ch]=ord(ch)-ord('a')+1
        pre=[0]*len(s)
        pre[0]=mp[s[0]]
        for i in range(1,len(s)):
            pre[i]+=pre[i-1]+mp[s[i]]
        min_val=pre[0]
        ans=0
        for i in range(len(s)):
            ans=max(ans,pre[i]-min_val)
            ans=max(ans,pre[i])
            min_val=min(min_val,pre[i])
        return ans
        