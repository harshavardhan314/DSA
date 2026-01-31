class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_subarray=nums[0];
        int maxSubarray=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_subarray=max(nums[i],curr_subarray+nums[i]);
            maxSubarray=max(maxSubarray,curr_subarray);
        }
        return maxSubarray;


        
    }
};