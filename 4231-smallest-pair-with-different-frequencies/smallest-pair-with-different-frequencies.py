class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        freq=Counter(nums)
        vals=list(freq.items())
        vals=sorted(vals)
        n=len(vals)
        for i in range(n):
            for j in range(i+1,n):
                if vals[i][1]!=vals[j][1]:
                    return [vals[i][0],vals[j][0]]
        return [-1,-1]
                        
            
        