class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        vector<int>new_nums;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                new_nums.push_back(nums[i-1]);
            }
        }
        new_nums.push_back(nums.back());
        int j=0;
        for(int i=0;i<new_nums.size();i++){
            nums[i]=new_nums[j];
            j++;
        }
        int ans=new_nums.size();
        return ans;

        // T.c=O(n)+O(k)
        // S.c=O(k)
        // where k is no of unique elements in the array..
    }
};