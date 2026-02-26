def check(mid,nums,k):
    n=len(nums)
    cnt=0
    i=0
    while i<n:
        if nums[i]<=mid:
            cnt+=1
            i+=2
        else:
            i+=1
    return cnt>=k


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        l=min(nums)
        h=max(nums)
        ans=h
        while l<=h:
            mid=(l+h)//2
            if check(mid,nums,k):
                ans=mid
                h=mid-1
            else:
                l=mid+1
        return ans

        