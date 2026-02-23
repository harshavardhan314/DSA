class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        freq=defaultdict(int)

        for i in range(len(s)):
            if i+k-1<len(s):
                temp=s[i:i+k]
                freq[temp]+=1
        req=(1<<k)
        for i in range(0,req):
            val=bin(i)[2:]
            rem=k-len(val)
            temp=""
            while  rem>0:
                temp+='0'
                rem-=1
            val=temp+val
            if val not in freq:
                return False
                
        return True


        