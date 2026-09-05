class Solution {
public:
    int trap(vector<int>& nums) {

        int n=nums.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        int ans=0;
        while(l<=r){

            if(nums[l]<=nums[r]){
                if(nums[l]<lmax){
                    ans+=lmax-nums[l];
                    
                }
                else{
                    lmax=max(lmax,nums[l]);
                }
                l++;
            }
            else{
                if(nums[r]<rmax)
                ans+=rmax-nums[r];
                else{
                    rmax=max(rmax,nums[r]);
                }
                r--;

            }

        }
        return ans;
        
    }
};