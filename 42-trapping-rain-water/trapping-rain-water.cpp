class Solution {
public:
    int trap(vector<int>& nums) {

        int n=nums.size();
        int ans=0;
        int left=0;
        int right=n-1;
        int max_left=0;
        int max_right=0;
        while(left<=right){

            if(nums[left]<=nums[right]){

                if(nums[left]>=max_left){
                    max_left=nums[left];
                }
                else{
                    ans+=max_left-nums[left];
                }
                left++;
            }
            else{

                if(nums[right]>=max_right){
                    max_right=nums[right];
                }
                else{
                    ans+=max_right-nums[right];
                }
                right--;
            }
        }
        return ans;

        
    }
};