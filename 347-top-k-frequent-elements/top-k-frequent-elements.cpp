class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        using T=pair<int,int>;
        priority_queue<T,vector<T>,greater<T>>pq;
        for(auto it:mp){
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                if(!pq.empty() && pq.top().first<it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        
    }
};