class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n=len(s)
        val=[]
        cnt_0=1
        cnt_1=1
        for i in range(1,n):
            if s[i]==s[i-1]:
                if s[i]=='0':
                    cnt_0+=1
                else:
                    cnt_1+=1
            else:
                val.append(max(cnt_0,cnt_1))
                cnt_0=1
                cnt_1=1
        
        val.append(max(cnt_0,cnt_1))
        mp=defaultdict(int)
        mp[0]=1
        cnt=0
        ans=0
        for i in range(1,len(val)):
            cnt+=min(val[i],val[i-1])
        return cnt

            


        