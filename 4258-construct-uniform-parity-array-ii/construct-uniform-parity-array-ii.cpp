class Solution {
public:
    bool uniformArray(vector<int>& nums) {

   
        int min_odd=INT_MAX;
        int min_even=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2)min_odd=min(min_odd,nums[i]);
            else
            min_even=min(min_even,nums[i]);
        }

        //even
        bool found=true;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                if(nums[i]-min_odd<1)found=false;
            }
        }
        if(found)return true;
        found=true;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                if(nums[i]-min_odd<1)found=false;

            }
        }
        if(found)return true;
        return false;
        
    }
};