class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n=len(nums)
        ans=n
        val=sum(nums)
        remove=val%p
        if remove==0:
            return 0
        temp=0
        mp={0:-1}
        for i in range(n):
            temp=(temp+nums[i])%p
            need=(temp-remove+p)%p
            if need in mp:
                ans=min(ans,i-mp[need])
            
            mp[temp]=i
        
        return -1 if ans==n else ans

            

        