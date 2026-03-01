class Solution:
    def makeParityAlternating(self, nums: List[int]) -> List[int]:
        n=len(nums)
        def solve(par:int)->(int,int):
            ops=0
            vals=[]
            for i,val in enumerate(nums):
                if par&1 == val&1:
                    vals.append((val,i))
                else:
                    ops+=1
                    vals.append((val+1,i))
                    vals.append((val-1,i))
                par+=1
            
            vals.sort()
            
            l=0
            cnt=0
            seen=[0]*n
            best_range=10**20
            for r in range(len(vals)):
                rv,idx=vals[r]
                cnt+=seen[idx]==0
                seen[idx]+=1

                while cnt==n:
                    lv,li=vals[l]
                    best_range=min(best_range,rv-lv)
                    seen[li]-=1
                    cnt-=seen[li]==0
                    l+=1
            
            return [ops,best_range]
        
        return min(solve(1),solve(0))
                    
                





                