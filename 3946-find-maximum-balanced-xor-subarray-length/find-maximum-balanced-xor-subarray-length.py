class Solution:
    def maxBalancedSubarray(self, nums: List[int]) -> int:
        n=len(nums)
        pre=[0]*n
        pre_xor=[0]*n
        pre[0]=1
        if nums[0]%2!=0:
            pre[0]=-1
        pre_xor[0]=nums[0]
        for i in range(1,len(nums)):
            pre_xor[i]=pre_xor[i-1]^nums[i]
            pre[i]+=pre[i-1]
            if nums[i]%2==0:
                pre[i]+=1
            else:
                pre[i]-=1
        
        ans=0
        mp=defaultdict(int)
        mp[(0,0)]=-1
        for i in range(len(nums)):
            if (pre_xor[i],pre[i]) in mp:
                pre_idx=mp[(pre_xor[i],pre[i])]
                ans=max(ans,i-pre_idx)
            else:
                mp[(pre_xor[i],pre[i])]=i        
        return ans

