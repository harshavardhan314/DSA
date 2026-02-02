class Solution {
public:
    int longestAlternating(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>>left_dp(n,vector<int>(2,1));
        vector<vector<int>>right_dp(n,vector<int>(2,1));
        int ans=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                left_dp[i][1]=left_dp[i-1][0]+1;
            }
            else if(nums[i-1]<nums[i]){
                left_dp[i][0]=left_dp[i-1][1]+1;
            }
            ans=max({ans,left_dp[i][0],left_dp[i][1]});
        }
        

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                right_dp[i][1]=right_dp[i+1][0]+1;
            }
            else if(nums[i]<nums[i+1]){
                right_dp[i][0]=right_dp[i+1][1]+1;
            }

            ans=max({ans,right_dp[i][0],right_dp[i][1]});
        }


        for(int i=1;i<n-1;i++){
            if(nums[i-1]<nums[i+1]){
                ans=max(ans,left_dp[i-1][1] + right_dp[i+1][1]);
            }
            else if(nums[i-1] > nums[i+1]){
                ans=max(ans,left_dp[i-1][0] + right_dp[i+1][0]);
            }
        }
        return ans;


        
    }
};