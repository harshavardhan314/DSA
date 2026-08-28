class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end());
        int last=points[0][1];
        int ans=1;
        int n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]>last){
                last=points[i][1];
                ans++;
            }
            else{
                last=min(last,points[i][1]);
            }
        }
        return ans;
        
    }
};