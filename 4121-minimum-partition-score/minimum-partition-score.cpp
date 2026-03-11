class Solution {
    long long pre[1001];
    long long dp[1001][1001]; 
    int n;

    long long solve(int i, int par, vector<int>& nums) {
        
        if (par == 0) {
            long long last_seg = pre[n] - pre[i];
            return (last_seg * (last_seg + 1)) / 2;
        }

        
        if (dp[i][par] != -1) return dp[i][par];

        long long ans = 1e18; 

        
        for (int j = i; j <= n - 1 - par; j++) {
            long long sum = pre[j + 1] - pre[i];
            long long cost = (sum * (sum + 1)) / 2;

            if(cost>=ans)break;

            
            ans = min(ans,cost+ solve(j + 1, par - 1, nums));

        
            
            
        }
        return dp[i][par] = ans;
    }

public:
    long long minPartitionScore(vector<int>& nums, int k) {
        n = nums.size();
        
        
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(0, k - 1, nums);
    }
};