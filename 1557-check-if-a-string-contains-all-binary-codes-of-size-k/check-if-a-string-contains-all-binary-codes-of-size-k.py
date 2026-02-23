class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        freq=defaultdict(int)

        for i in range(len(s)):
            if i+k-1<len(s):
                temp=s[i:i+k]
                freq[temp]+=1
        req=(1<<k)
        print(freq)
        for i in range(0,req):
            val=bin(i)[2:]
            rem=k-len(val)
            arr=[]
            while  rem>0:
                arr.append('0')
                rem-=1
            temp="".join(arr)
            val=temp+val
            if val not in freq:
                return False
                
        return True


        