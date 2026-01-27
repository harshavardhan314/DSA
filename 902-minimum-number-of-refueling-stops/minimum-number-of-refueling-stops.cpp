class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int max_dist=startFuel;
        int n=stations.size();
        int i=0;
        int ans=0;
        if(max_dist>=target)return 0;
        priority_queue<int>pq;
        while(max_dist<target){

            while(i<n && stations[i][0]<=max_dist)
            {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())return -1;
            max_dist+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;

        
    }
};