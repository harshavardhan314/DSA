class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        val=sum(apple)
        capacity.sort(reverse=True)
        ans=0
        temp_sum=0
        for i in capacity:
            if temp_sum<val:
                ans+=1
                temp_sum+=i
        return ans
        