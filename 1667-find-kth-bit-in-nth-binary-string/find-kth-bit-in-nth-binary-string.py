class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        res="0"
        for i in range(n):
            t=res[::-1]
            val=""
            for j in range(len(t)):
                if t[j]=="1":
                    val+="0"
                elif t[j]=="0":
                    val+="1"
            
            temp="1"+val
            res=res+temp
        
        for i in range(len(res)):
            if i==k-1:
                return res[i]
        
        
        return ""