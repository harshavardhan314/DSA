long long int rec(int i,vector<int>&arr,vector<int>&dp){
    int n=arr.size();
    if(i>=n)return 0;
    int take=0;
    if(dp[i]!=INT_MIN)return dp[i];
    long long int ans=INT_MIN;
    for(int k=0;k<3 && i+k<n;k++){
        take+=arr[i+k];
        ans=max(ans,take-rec(i+k+1,arr,dp));
    }
    return dp[i]=ans;
    
}

class Solution {
public:
    string stoneGameIII(vector<int>&arr) {
        int n=arr.size();

        vector<int>dp(n,INT_MIN);
        long long int val=rec(0,arr,dp);
        if(val==0)return "Tie";
        if(val<0)return "Bob";
        if(val>0)return "Alice";
        return "";
    }
};