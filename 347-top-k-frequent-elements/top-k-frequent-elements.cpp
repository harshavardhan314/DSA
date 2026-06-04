class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int n=nums.size();
        // using bucket sort..
        vector<vector<int>>bucket(n+1);
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=n;i>=1 && ans.size()<k;i--){
            for(auto it:bucket[i]){
                ans.push_back(it);
                if(ans.size()==k)break;
            }
        }
        return ans;

        
    }
};