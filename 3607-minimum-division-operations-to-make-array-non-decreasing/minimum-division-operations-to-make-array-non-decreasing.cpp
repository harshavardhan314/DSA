class Solution {
public:
int pd(int n) {
    if (n == 1) return 0; 

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return n / i;
        }
    }
    
    return 1;
}

    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[n-1];
        int cnt=0;
        for(int i=n-2;i>=0;i--)
        {
            while(nums[i]>prev && pd(nums[i])!=1)
            {
                int div=pd(nums[i]);
                nums[i]=nums[i]/div;
                cnt++;
            }
            if(nums[i]>prev)return -1;
            prev=nums[i];
        }
        return cnt;
        
    }
};