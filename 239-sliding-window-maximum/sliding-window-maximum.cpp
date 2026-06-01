class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>ms;
        
        int n=nums.size();
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        vector<int>res;
        res.push_back(*ms.rbegin());
        int l=0;
        for(int i=k;i<n;i++){
            ms.erase(ms.find(nums[l]));
            ms.insert(nums[i]);
            res.push_back(*ms.rbegin());
            l++;
        }
        return res;
    }
};