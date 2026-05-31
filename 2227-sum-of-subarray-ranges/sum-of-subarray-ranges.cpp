class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int min_val=nums[i];
            int max_val=nums[i];
            for(int j=i;j<n;j++){
                min_val=min(min_val,nums[j]);
                max_val=max(max_val,nums[j]);
                ans+=max_val-min_val;
            }
        }
        return ans;
        
    }
};