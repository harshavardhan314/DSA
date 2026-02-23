class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        

        while(nums.size()>1){
            
            vector<int>new_nums;
            int cnt=0;
            for(int i=0;i<nums.size()-1;i+=2){

                if(cnt%2==0)new_nums.push_back(min(nums[i],nums[i+1]));
                else{
                    new_nums.push_back(max(nums[i],nums[i+1]));
                }
                cnt++;

            }
            nums=new_nums;
            
        }
        return nums[0];
        
    }
};