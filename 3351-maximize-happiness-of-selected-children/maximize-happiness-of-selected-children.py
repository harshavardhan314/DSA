class Solution:
    def maximumHappinessSum(self, arr: List[int], k: int) -> int:
        arr.sort(reverse=True)
        val=0
        x=0
        for i in range(k):
            val+=max(arr[i]-x,0)
            x+=1
        return val

        