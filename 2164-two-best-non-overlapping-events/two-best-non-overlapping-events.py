class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n=len(events)
        dp=[[-1]*3 for _ in range(n)]
        def rec(idx,cnt):
            if idx==n:
                return 0
            if cnt==2:
                return 0
            if dp[idx][cnt]!=-1:
                return dp[idx][cnt]
            st,end,val=events[idx]
            not_pick=rec(idx+1,cnt)
            l=0
            h=n-1
            next_idx=n
            while l<=h:
                mid=(l+h)//2
                if events[mid][0]>=events[idx][1]+1:
                    next_idx=mid
                    h=mid-1
                else:
                    l=mid+1
            pick=val+rec(next_idx,cnt+1)
            dp[idx][cnt]=max(pick,not_pick)
            return max(pick,not_pick)
        return rec(0,0)
        

        