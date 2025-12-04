class Solution:
    def countCollisions(self, s: str) -> int:
        freq=defaultdict(int)
        last=s[0]
        ans=0
        freq[s[0]]+=1
        for i in range(1,len(s)):
            freq[s[i]]+=1
            if s[i]=='L':
                if last=='R':
                    ans+=2
                    ans+=freq['R']-1
                    freq['R']=0
                    freq['S']+=1
                elif freq['S']>0:
                    ans+=1
            elif s[i]=='S':
                ans+=freq['R']
                freq['R']=0
            last=s[i]
        return ans
                

        