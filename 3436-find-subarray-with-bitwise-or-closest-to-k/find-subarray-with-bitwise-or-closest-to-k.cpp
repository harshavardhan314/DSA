class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>prev;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            set<int>new_val;
            for(auto it:prev)
            {
                new_val.insert(it|nums[i]);
            }
            new_val.insert(nums[i]);
            for(auto it:new_val)
            {
                ans=min(ans,abs(k-it));
            }
            prev=new_val;
        }
        return ans;
        
    }
};