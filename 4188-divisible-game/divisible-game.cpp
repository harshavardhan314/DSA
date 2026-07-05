class Solution {
public:
     long long MOD = 1000000007;

    long long find(int k, const vector<int>& nums) {
    long long curr_sum =  (nums[0] % k == 0) ? nums[0] : -1LL * nums[0];
    long long ans = curr_sum;

    for (int i = 1; i < nums.size(); i++) {
        
        long long val = (nums[i] % k == 0) ? nums[i] : -1LL * nums[i];
        
       
        curr_sum = max(val, curr_sum + val);
        ans = max(ans, curr_sum);
    }

    return ans;
}

    int divisibleGame(vector<int>& nums) {
        set<int> div={2};

        
        for (int num : nums) {
            int x = num;
            for (int j = 2; 1LL * j * j <= x; j++) {
                if (x % j == 0) {
                    div.insert(j);
                    while (x % j == 0)
                        x /= j;
                }
            }
            if (x > 1)
                div.insert(x);
        }

        

        long long bestScore = LLONG_MIN;
        int bestK = INT_MAX;

        for (int k : div) {
            long long score = find(k, nums);

            if (score > bestScore) {
                bestScore = score;
                bestK = k;
            } else if (score == bestScore) {
                bestK = min(bestK, k);
            }
        }

        bestScore %= MOD;
        if (bestScore < 0)
            bestScore += MOD;

        return (int)((bestScore * bestK) % MOD);
    }
};