class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long ans=0;
        int n=units.size();
        int m=units[0].size();
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        for(int i=0;i<n;i++){
            priority_queue<int,vector<int>,greater<int>>pq;
            for(int j=0;j<m;j++){
                pq.push(units[i][j]);
            }
            pq1.push(pq.top());
            pq.pop();
            if(!pq.empty()){
                ans+=pq.top();
                pq2.push(pq.top());
            }

        }
        if(pq2.empty()){
            while(!pq1.empty()){
                ans+=pq1.top();
                pq1.pop();
            }
            return ans;
        }
        else{
            ans-=pq2.top();
            ans+=pq1.top();
        }
        return ans;

        
    }
};