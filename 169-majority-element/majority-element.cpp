class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                element=nums[i];
            }
            if(nums[i]==element)cnt++;
            else cnt--;
        }
        return element;

    }
};