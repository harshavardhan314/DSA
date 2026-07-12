class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        temp=list(arr)
        if len(temp)==0:
            return []
        temp.sort()
        mp=defaultdict(int)
        rank=1
        mp[temp[0]]=rank
        for i in range(1,len(temp)):
            if temp[i]!=temp[i-1]:
                rank+=1
            mp[temp[i]]=rank
        ans=[]
        
        for i in arr:
            ans.append(mp[i])
        return ans

        