class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        val=sum(nums)
        st=0
        ans=0
        n=len(nums)
        for i in range(n-1):
            st+=nums[i]
            temp=val-2*st
            print(temp)
            if temp%2==0 :
                ans+=1
        return ans
        