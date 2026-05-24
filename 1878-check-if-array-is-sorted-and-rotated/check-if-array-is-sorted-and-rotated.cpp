class Solution {
public:
    bool check(vector<int>& nums) {

        // to be array in sorted manner .. we should have only one peak point 
        // try finding that ..

        int peak_point=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int next_idx=(i+1)%n;
            if(nums[i]>nums[next_idx]){
                peak_point++;
            }

        }
        return peak_point<=1;

        // T.c=O(N)
        // S.c=O(1)
        
    }
};