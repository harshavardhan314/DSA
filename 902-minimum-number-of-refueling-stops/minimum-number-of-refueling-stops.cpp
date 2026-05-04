class Solution {
public:
    int minRefuelStops(int t, int sf, vector<vector<int>>& s) {


        int val=sf;
        int ans=0;

        priority_queue<int>pq;
        for(auto it:s){
            int st_pt=it[0];
            int dist=it[1];
            while(!pq.empty() && val<st_pt){
                val+=pq.top();
                ans++;
                pq.pop();
            }
            if(val>=st_pt){
                pq.push(dist);
            }
            else{
                return -1;
            }

        }
        while(!pq.empty() && val<t){
            val+=pq.top();
            pq.pop();
            ans++;

        }
        if(val<t) return -1;
        return ans;

        
    }
};