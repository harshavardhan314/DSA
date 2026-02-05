class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n=nums.size();
        vector<int>res(n);
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
             idx=(i+nums[i])%n;
            }
            else if(nums[i]<0){
                int val=abs(nums[i])%n;
               idx= (i-val+n)%n;
              
                
            }
            else{
                idx=i;
            }
            res[i]=nums[idx];
        }
        return res;
        
    }
};