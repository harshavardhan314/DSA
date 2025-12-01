class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        arr=[]
        for i in range(0,len(s),k):
            if i+k<len(s):
                print(i)
                temp=s[i:i+k]
                arr.append(temp)
            else:
                temp=s[i:]
                while len(temp)<k:
                    temp+=fill
                arr.append(temp)
        
        return arr

        