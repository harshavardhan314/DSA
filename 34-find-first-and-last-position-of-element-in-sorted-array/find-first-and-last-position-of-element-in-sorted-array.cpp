class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int st_idx=-1;
        int end_idx=-1;
        if(n==0)return {st_idx,end_idx};

        // st_idx

        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=target){
                st_idx=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        if(st_idx==-1 || nums[st_idx]!=target)return {-1,-1};

        // end_idx

        l=0;
        h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<=target){
                end_idx=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return {st_idx,end_idx};

        

    }
};