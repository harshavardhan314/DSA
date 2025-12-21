class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& f) {

        map<int,int>freq_nums,freq_f,matching;
        int n=nums.size();
        int cnt=0;
        int max_cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==f[i])
            {
                matching[nums[i]]++;
                cnt++;
                max_cnt=max(max_cnt,matching[nums[i]]);
            }
            freq_nums[nums[i]]++;
            freq_f[f[i]]++;
        }
        for(auto[x,f]:freq_nums)
        {
            if(f>n-freq_f[x])return -1;
        }
        return max(max_cnt,(cnt+1)/2);

        
    }
};