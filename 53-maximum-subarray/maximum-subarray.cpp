class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=nums[0];
        int ans=sum;
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum=max(sum+nums[i],nums[i]);
           ans=max(ans,sum);
        }
        return ans;
        
    }
};