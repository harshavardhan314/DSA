class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
                {
                    ans=mid;
                }
            if(nums[l]<=nums[mid])
            {
               
               if(nums[l]<=target and target<=nums[mid]) 
                    h=mid-1;
                else
                l=mid+1;
            }
            else
            {
                if(nums[mid]<=target and target<=nums[h])
               l=mid+1;
               else
                    h=mid-1;
                

            }
        }
        return ans;
        
    }
};