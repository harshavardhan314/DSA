class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        multiset<int>ms;
        for(int i=0;i<n;i++){
            ms.insert(nums[i]);
        }
        map<int,int>mp;
        multiset<int>temp;
        for(int i=n-1;i>=0;i--){
            ans[i]=max(*ms.rbegin(),nums[i]);
            if (!temp.empty()) {
        auto idx = temp.lower_bound(*ms.rbegin());

        if (idx != temp.begin()) {        
            --idx;
            if (mp.find(*idx) != mp.end()) {
                ans[i] = max(ans[i], mp[*idx]);
            }
        }
    }

            temp.insert(nums[i]);
            if(mp.find(nums[i])==mp.end())
            mp[nums[i]]=ans[i];
            else
            {
                mp[nums[i]]=max(ans[i],mp[nums[i]]);
            }
            ms.erase(ms.find(nums[i]));
         
        }
        return ans;

        
    }
};