class Solution {
public:
    bool canPartition(vector<int>& nums) {


        int total_sum=0;
        for(int i=0;i<nums.size();i++) total_sum+=nums[i];

        if(total_sum%2)return false;

        int target_sum=total_sum/2;

        int n=nums.size();
        vector<int>dp(target_sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=target_sum;j>=nums[i];j--){
                dp[j]=dp[j]|dp[j-nums[i]];
            }
            if(dp[target_sum])return true;
        }
        return false;


        
    }
};