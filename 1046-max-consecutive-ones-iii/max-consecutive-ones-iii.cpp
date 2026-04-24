class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int sum=0;
        int l=0;
        int ans=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(r-l+1-sum>k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);

        }
        return ans;
        
    }
};