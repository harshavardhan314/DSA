class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vp;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({nums1[i],i});
        }

        sort(vp.begin(),vp.end());

        priority_queue<long long ,vector<long long>,greater<long long >>pq;
        int i=0;
        unordered_map<long ,long>track;
        long long sum=0;
        while(i<n)
        {
            int idx=vp[i].second;
            int val=vp[i].first;
            track[val]=sum;
            while(i<vp.size() && vp[i].first==val){
                int temp=vp[i].second;
                pq.push(nums2[temp]);
                sum+=nums2[temp];

                if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
                }

                i++;
            }
        }
        vector<long long >ans(n);
        for(int i=0;i<n;i++){
            ans[i]=track[nums1[i]];
        }
        return ans;
        
    }
};