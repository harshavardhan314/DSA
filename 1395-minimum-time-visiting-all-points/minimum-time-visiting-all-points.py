class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans=0
        n=len(points)
        for i in range(n-1):
            x_dir=abs(points[i+1][0]-points[i][0])
            y_dir=abs(points[i+1][1]-points[i][1])
            ans+=max(x_dir,y_dir)
        return ans

        