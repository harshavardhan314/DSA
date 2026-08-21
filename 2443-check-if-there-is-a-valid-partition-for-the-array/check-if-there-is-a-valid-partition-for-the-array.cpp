bool rec(int idx,vector<int>&nums,vector<int>&dp){

    int n=nums.size();

    if(idx>=n)return true;

    bool op1=false,op2=false,op3=false;

    if(dp[idx]!=-1)return dp[idx];

    if(idx+1<n && nums[idx] == nums[idx+1]){
   
        op1 = op1 || rec(idx+2,nums,dp); 

    }

    if(idx+2<n && nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2]){
        op2 = op2 || rec(idx+3,nums,dp); 
    }

    if(idx+2<n && nums[idx+1]-nums[idx]==1 && nums[idx+2]-nums[idx+1]==1 ){
        op3 = op3 || rec(idx+3,nums,dp);
    }
    return dp[idx] = op1 || op2 || op3;
    
    
}


class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return rec(0,nums,dp);
    }
};