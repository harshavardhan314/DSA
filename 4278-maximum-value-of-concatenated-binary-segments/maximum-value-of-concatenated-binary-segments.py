class Solution:
    def maxValue(self, n1: list[int], n0: list[int]) -> int:

        vals=[]
        n=len(n1)
        for i in range(n):
            temp=('1'*n1[i])+('0'*n0[i])
            vals.append(temp)
        
        def cmp(a,b):
            if a+b>b+a:
                return -1
            else:
                return 1
        vals.sort(key=cmp_to_key(cmp))
        final=''.join(vals)

        return int(final,2)%(10**9+7)
            
        
        