def check(curr):
    return curr==curr[::-1]
class Solution:
    def countSubstrings(self, s: str) -> int:
        n=len(s)
        cnt=0
        for i in range(n):
            curr=""
            for j in range(i,n):
                curr+=s[j]
                if check(curr):
                    cnt+=1
        
        return cnt




        