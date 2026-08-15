class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0)cnt++;
            val=val^nums[i];
        }
        if(cnt==0)return 0;
        if(val>0)return n;
        return n-1;
        
    }
};