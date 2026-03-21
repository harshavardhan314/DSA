
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int val=0;
        for(int i=0;i<nums.size();i++){
            if(i>val)return false;
            val=max(val,i+nums[i]);
        }
        return true;
    }
};