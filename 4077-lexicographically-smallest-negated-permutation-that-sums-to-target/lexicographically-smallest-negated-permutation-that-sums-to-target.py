class Solution:
    def lexSmallestNegatedPerm(self, n: int, target: int) -> List[int]:
        have=(n*(n+1))//2
        ans=[]
        if target>have or target<-have or (have-target)%2:
            return ans
        

        for i in range(1,n+1):
            ans.append(i)
        
        rem=(have-target)//2
        val=0
        for i in range(len(ans)-1,-1,-1):
            if val+ans[i]<=rem:
                val+=ans[i]
                ans[i]=-1*ans[i]
        ans.sort()
        return ans
        
        