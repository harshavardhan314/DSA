
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {

        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        int ans=h;
        int n=nums.size();

        while(l<=h){
            int mid=(l+h)/2;
            int take=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    take++;
                    i++;
                }
            }
            if(take>=k){
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