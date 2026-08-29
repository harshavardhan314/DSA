long long solve(int i,vector<int>&nums,int k,vector<long long int>&p,vector<vector<long long >>&dp){

    int n=nums.size();
    

     
    if(k==0){
        long long temp=p[n-1];
        if(i-1>=0)temp-=p[i-1];
        return (temp*(temp+1))/2;
    }
      if(dp[i][k]!=-1) return dp[i][k]; 

    long long ans=LONG_MAX;
    for(int j=i;j<n-k;j++){
        long long int sum=p[j];
        if(i-1>=0)sum-=p[i-1];
        long long int curr_val=(sum*(sum+1))/2;
        if(curr_val>=ans)break;

        ans=min(ans,curr_val+solve(j+1,nums,k-1,p,dp));
    }
    return dp[i][k]=ans;
}


class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long int>p(n,0);
        for(int i=0;i<n;i++){
            p[i]=nums[i];
            if(i-1>=0)p[i]+=p[i-1];
        }

        vector<vector<long long >>dp(n,vector<long long >(k+1,-1));

        return solve(0,nums,k-1,p,dp);

        
    }
};