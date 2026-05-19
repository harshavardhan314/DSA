int rec(int i,vector<int>&nums,int curr_sum,int total_sum,vector<vector<int>>&dp){

    if(i==nums.size()){
        if(curr_sum*2==total_sum)return 1;
        return 0;

    }
    if(dp[i][curr_sum]!=-1)return dp[i][curr_sum];
    int pick=rec(i+1,nums,curr_sum+nums[i],total_sum,dp);
    int not_pick=rec(i+1,nums,curr_sum,total_sum,dp);
    return dp[i][curr_sum]=pick||not_pick;

}




class Solution {
public:
    bool canPartition(vector<int>& nums) {


        int total_sum=0;
        for(int i=0;i<nums.size();i++) total_sum+=nums[i];

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(total_sum+1,-1));
        return rec(0,nums,0,total_sum,dp);

        
    }
};