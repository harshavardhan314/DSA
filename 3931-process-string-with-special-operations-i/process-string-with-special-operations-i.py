class Solution:
    def processStr(self, s: str) -> str:
        res=""
        for i in s:
            if i=='*':
                temp=res[:-1]
                res=temp
               
            elif i=='#':
                res+=res
            elif i=='%':
                res=res[::-1]
            else:
                res+=i
        
        return res
        