bool can_split(int mid,vector<int>&nums,int k){
    int n=nums.size();
    int curr_sum=0;
    int splits=1;
    for(int i=0;i<n;i++){
        
        if(curr_sum+nums[i]>mid){
            curr_sum=nums[i];
            splits++;
        }
        else{
            curr_sum+=nums[i];
        }
    }
    return splits<=k;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0LL);
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(can_split(mid,nums,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};