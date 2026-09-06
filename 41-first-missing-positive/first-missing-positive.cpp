class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=1;
        for(int i=0;i<n;i++){
            if(nums[i]<=0)continue;
            else if(i-1>=0 && nums[i]==nums[i-1])continue;
            else {
                
                if(nums[i]==val)val++;
                else
                return val;
            }
        }
        return val;
        
    }
};