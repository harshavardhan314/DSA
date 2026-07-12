class Solution {
public:
    int rob(vector<int>& nums) {


        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            dp[i]=nums[i];
            if(i-2>=0){
                dp[i]+=dp[i-2];
            }
            dp[i]=max(dp[i-1],dp[i]);
        }
        int val=dp[n-2];
        dp.assign(n,0);
        for(int i=1;i<n;i++){
            dp[i]=nums[i];
            if(i-2>=0){
                dp[i]+=dp[i-2];
            }
            dp[i]=max(dp[i-1],dp[i]);
        }
        return max(dp[n-1],val);

        
    }
};