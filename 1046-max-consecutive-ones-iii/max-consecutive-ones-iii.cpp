class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0;
        int n=nums.size();
        int ones=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==1)ones++;

            while(((r-l+1)-ones)>k){
                if(nums[l]==1)ones--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};