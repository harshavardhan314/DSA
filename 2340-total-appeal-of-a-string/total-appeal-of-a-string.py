class Solution:
    def appealSum(self, s: str) -> int:
        n=len(s)
        ans=0
        last_pos=[-1]*26

        for i,val in enumerate(s):
            curr_val=ord(val)-ord('a')
            ans+=(i-last_pos[curr_val])*(n-i)
            last_pos[curr_val]=i
            
        return ans

        