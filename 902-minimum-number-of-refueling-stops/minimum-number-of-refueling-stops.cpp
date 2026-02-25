class Solution {
public:
    int minRefuelStops(int target, int s, vector<vector<int>>& st) {
        int fuel=s;
        int stops=0;
        int n=st.size();
        priority_queue<int>pq;
        for (int i=0;i<n;i++){
            int dist=st[i][0];
            int f=st[i][1];
            while(fuel<dist && !pq.empty()){
                fuel+=pq.top();
                pq.pop();
                stops++;
            }
            if(fuel>=dist){
                pq.push(f);

            }
            else
            {
                return -1;
            }
        }
        while(fuel<target && !pq.empty()){
            fuel+=pq.top();
            pq.pop();
            stops++;
        }
        if(fuel<target)return -1;
        return stops;
        
    }
};