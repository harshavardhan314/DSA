class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n=nums.size();

        int low=0;
        int high=n-1;
        int mid=0;

        // [0...low-1] ----> all zeros..
        // [low.. mid-1] ----> all ones..
        // [mid...high]---> unsorted array
        // [high+1...n-1]----> all twos..

        // we try to make this unsorted array to sort..

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;

            }
        }

        // T.c= O(n)
        // s.c=O(1)

        
    }
};