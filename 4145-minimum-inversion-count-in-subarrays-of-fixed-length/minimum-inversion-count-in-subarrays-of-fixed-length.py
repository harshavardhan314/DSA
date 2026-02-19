class Solution:
    def minInversionCount(self, nums: List[int], k: int) -> int:
        n=len(nums)
        sl=[]
        inv_cnt=0
        ans=float(inf)
        for i in range(n):

            if i-k>=0:
                smaller=bisect_left(sl,(nums[i-k],0))
                inv_cnt-=smaller
                pos=bisect_left(sl,(nums[i-k],i-k))
                if pos<len(sl) and sl[pos] == (nums[i-k],i-k):
                    sl.pop(pos)

            greater =len(sl) - bisect_right(sl,(nums[i],10**18))
            inv_cnt+=greater
            pos=bisect_right(sl,(nums[i],i))
            sl.insert(pos,(nums[i],i))

            if i>=k-1:
                ans=min(ans,inv_cnt)
            

        
        return ans

        