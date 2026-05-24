class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int cnt=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]!=0){
                nums[j]=nums[i];
                i++;
                j++;
            }
            else{
                cnt++;
                i++;
            }
        }
        while(cnt>0){
            nums[j]=0;
            cnt--;
            j++;
        }

        
    }
};